class Solution {
    int res = 0;
public:
    int countArrangement(int N) {
        vector<int>v(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            v[i]++;
            backtrack(2, v, N);
            v[i]--;
        }
        return res;
    }
    void backtrack(int st, vector<int>& v, int N) {
        if (st == N + 1) {res++;}
        if (st <= N) {
            for (int i = 1; i <= N; i++) {
                if (v[i] == 0 && ((i % st) == 0 || (st % i) == 0)) {
                    v[i]++;
                    backtrack(st + 1, v, N);
                    v[i]--;
                }
            }
        }
    }
};