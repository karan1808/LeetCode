class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for (auto c : chars) {
            mp[c]++;
        }
        int res = 0;
        for (auto st : words) {
            unordered_map<char, int> mm;
            for (auto ch : st) {
                mm[ch]++;
            }
            int tes = 0;
            for (auto it : mm) {
                if (it.second > mp[it.first]) {tes = 1;}
            }
            if (tes == 0) {res += st.size();}
        }
        return res;
    }
};