class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mp;
        int res = INT_MAX;
        for (auto v : points) {mp[v[0]].insert(v[1]);}

        for (auto i = mp.begin(); i != mp.end(); i++) {
            for (auto j = next(i); j != mp.end(); j++) {
                vector<int> y;
                set_intersection(begin(i->second), end(i->second), begin(j->second), end(j->second)
                                 , back_inserter(y));
                for (int k = 1; k < y.size(); ++k) {
                    res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
                }
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};