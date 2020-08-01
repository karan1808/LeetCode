class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int yo = 0;
            int x = arr[i];
            while (x > 0) {
                if (x & 1) {yo++;}
                x >>= 1;
            }
            v.push_back(make_pair(yo, arr[i]));
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for (auto a : v) {
            res.push_back(a.second);
        }
        return res;
    }
};