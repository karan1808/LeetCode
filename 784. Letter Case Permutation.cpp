class Solution {
    vector<string> res;
public:
    vector<string> letterCasePermutation(string S) {
        backtrack(S, 0);
        return res;
    }
    void backtrack(string& s, int st) {
        if (st == s.size()) {res.push_back(s); return;}
        if (s[st] - '0' < 10) {backtrack(s, st + 1);} else {
            backtrack(s, st + 1);
            int c = s[st];
            if (c - 'A' <= 26 && c - 'A' >= 0) {c = 'a' + c - 'A';} else {
                c = 'A' + c - 'a';
            }
            s[st] = c;
            backtrack(s, st + 1);
        }
    }
};