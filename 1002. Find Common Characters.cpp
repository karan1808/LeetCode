class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        unordered_map<char, multiset<int>> mp;
        for (auto s : A) {
            unordered_map<char, int> mm;
            for (auto ch : s) {
                mm[ch]++;
            }
            for (auto it : mm) {
                // cout<<it.first<<" jkjl "<<it.second<<endl;
                mp[it.first].insert(it.second);
            }
        }
        vector<string> res = {};
        for (auto it : mp) {
            // set<int> T=it.second;
            cout << it.second.size() << endl;
            if (it.second.size() == n) {
                int x = *it.second.begin();
                while (x-- > 0) {
                    string sss = "";
                    sss += it.first;
                    res.push_back(sss);
                }
            }
        }
        return res;
    }
};