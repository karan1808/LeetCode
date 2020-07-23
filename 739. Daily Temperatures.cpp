class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {s.push(i);} else {
                if (T[s.top()] > T[i]) {
                    res[i] = s.top() - i;
                    s.push(i);
                } else {
                    while (!s.empty() && T[s.top()] <= T[i]) {
                        s.pop();
                    }
                    if (!s.empty()) {
                        res[i] = s.top() - i;
                        s.push(i);
                    } else {
                        s.push(i);
                    }
                }
            }
        }
        return res;
    }
};