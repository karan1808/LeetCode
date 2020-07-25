class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        if (n == 0) {return 0;}
        int size = 0;
        size = 1;
        mp[s[0]] = 0;
        int y = -1;
        for (int i = 1; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {size = max(size, i - y); mp[s[i]] = i;} else {
                if (mp[s[i]] > y) {y = mp[s[i]];}
                mp[s[i]] = i;
                size = max(size, (i - y));
            }
        }
        // size=max(size,n-y);

        return size;


    }
};