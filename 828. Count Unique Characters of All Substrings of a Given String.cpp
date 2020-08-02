class Solution {
public:
    int uniqueLetterString(string s) {
        int index[26][2];
        memset(index, -1, sizeof(int) * 52);
        for (int i = 0; i < 26; i++) {
            index[i][0] = -1;
            index[i][1] = -1;
        }
        int mod = pow(10, 9) + 7;
        int n = s.length();
        int res = 0;
        string S = s;
        for (int i = 0; i < n; i++) {
            int c = S[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; c++) {
            res = (res + (n - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        }
        return res;
    }
};