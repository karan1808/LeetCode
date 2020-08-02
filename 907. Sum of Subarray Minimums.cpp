class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> vr(n, n);
        stack<pair<int, int>> s;
        int mod = pow(10, 9) + 7;
        for (int i = 0; i < n; i++) {
            if (s.empty()) {s.push(make_pair(A[i], i));} else {

                while (!s.empty() && s.top().first >= A[i]) {
                    pair<int, int> p = s.top();
                    vr[p.second] = i;
                    s.pop();
                }
                s.push(make_pair(A[i], i));
            }
        }
        vector<int> vl(n, -1);
        stack<pair<int, int>> t;
        for (int i = n - 1; i >= 0; i--) {
            if (t.empty()) {t.push(make_pair(A[i], i));} else {

                while (!t.empty() && t.top().first > A[i]) {
                    pair<int, int> p = t.top();
                    vl[p.second] = i;
                    t.pop();
                }
                t.push(make_pair(A[i], i));
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += A[i] * (((i - vl[i]) * ((vr[i] - i) % mod)) % mod);
            res %= mod;
        }
        return res;
    }
};