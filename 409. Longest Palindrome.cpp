class Solution {
public:
    int longestPalindrome(string s) {
        int k = 0;
        unordered_map<char, int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        int res = 0;
        for (auto it : mp) {
            if (it.second % 2 == 0) {res += it.second;} else {res += it.second - 1; k = 1;}
        }
        return res + k;
    }
};