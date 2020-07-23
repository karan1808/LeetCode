class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> T;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {T.push(i);}
            if (s[i] == ')') {
                int top = T.top();
                T.pop();
                reverse(s.begin() + top + 1, s.begin() + i);
            }
        }
        string res = "";
        for (auto i : s) {
            if (i == '(' || i == ')') {} else {res += i;}
        }
        return res;
    }
};