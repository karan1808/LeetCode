class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();


        vector<long>prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + A[i];


        deque<int> q;

        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {

            while (!q.empty() && prefix_sum[i] - prefix_sum[q.front()] >= K) {

                ans = min(ans, (i - q.front()));
                q.pop_front();

            }


            while (!q.empty() && prefix_sum[i] - prefix_sum[q.back()] <= 0 ) {
                q.pop_back();
            }


            q.push_back(i);




        }

        return ans == INT_MAX ? -1 : ans;




    }
};