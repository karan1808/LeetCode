class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xq(n, 0);
        int i = 0;
        int rr = 0;
        for (auto a : arr) {
            rr ^= a;
            xq[i] = rr;
            i++;
        }
        vector<int> ans;
        for (auto q : queries) {
            if (q[0] > 0) {ans.push_back(xq[q[1]]^xq[q[0] - 1]);} else {
                ans.push_back(xq[q[1]]);
            }
        }
        return ans;
    }
};