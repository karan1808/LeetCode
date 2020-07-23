class Solution {
public:
    int scoreOfParentheses(string S) {
        int t = 0;
        int res = 0;
        for (int i = 0; i < S.length() - 1; i++) {
            if (S[i] == '(') {
                t++;
                if (S[i + 1] == ')') {
                    res += pow(2, t - 1);
                }
            } else {
                t--;
            }
        }
        return res;
    }
};