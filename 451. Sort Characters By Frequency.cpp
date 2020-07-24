class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        vector<pair<int, char>> v;

        for (auto it : mp) {
            v.push_back(make_pair(it.second, it.first));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        string res = "";
        for (int i = 0; i < v.size(); i++) {
            pair<int, char> p = v[i];
            int cou = p.first;
            char c = p.second;
            while ((cou--) > 0) {
                res += c;
            }
        }

        return res;

    }
};