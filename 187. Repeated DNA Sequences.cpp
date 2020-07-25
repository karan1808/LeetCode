class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> res;
        unordered_map<string, int> mp;
        int n = s.size();
        if (n < 10) {return res;}
        string T = "";

        for (int i = 0; i < 10; i++) {
            T += s[i];
        }
        mp[T] = 1;

        for (int i = 10; i < n; i++) {
            T.erase(T.begin() + 0);
            T += s[i];
            if (mp.find(T) == mp.end()) {
                mp[T] = 1;
            } else {
                if (mp[T] == 1) {res.push_back(T); mp[T]++;}
            }

        }


        return res;
    }
};