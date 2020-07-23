class Solution {
public:
    string removeOuterParentheses(string S) {

        string s = S;
        stack<char>stk;
        string st = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
                if (stk.size() != 1)
                    st += '(';
            }
            else
            {
                stk.pop();

                if (!stk.empty())
                    st += ")";

            }
        }

        return st;
    }
};