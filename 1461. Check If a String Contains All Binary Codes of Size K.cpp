class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int n = s.size();
        int d = 0;
        for (int i = 0; i < n; i++) {
            d = (d << 1) | (s[i] - '0');
            if (i >= k - 1) {
                st.insert(d);
                d -= ((s[i - (k - 1)] - '0') << (k - 1));
            }
        }
        return ((st.size()) == (1 << k));
    }
};
