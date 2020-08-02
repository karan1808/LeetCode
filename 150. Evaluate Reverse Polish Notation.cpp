class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        stack<char> c;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            // cout<<s.size()<<endl;
            char xx = tokens[i][0];
            if (tokens[i].size() == 1 && (xx == '+' || xx == '*' || xx == '/' || xx == '-')) {
                char ch = xx;
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                if (ch == '+') {x = x + y;}
                if (ch == '*') {x = x * y;}
                if (ch == '/') {x = x / y;}
                if (ch == '-') {x = x - y;}
                s.push(x);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};