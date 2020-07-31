class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = worker.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back(make_pair(profit[i], difficulty[i]));
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());

        int res = 0;
        int poi = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int d = v[i].second;

            while (poi >= 0 && worker[poi] >= d) {
                res += v[i].first;
                poi--;
            }


        }
        return res;

    }
};