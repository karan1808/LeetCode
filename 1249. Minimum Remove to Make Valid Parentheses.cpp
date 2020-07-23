class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<pair<char, int>> T;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') {

                if (T.empty()) {
                    T.push(make_pair(s[i], i));
                } else {
                    pair<char, int> p;
                    p = T.top();

                    if (p.first == '(' && s[i] == ')') {
                        T.pop();
                    } else {
                        T.push(make_pair(s[i], i));
                    }
                }
            }
        }
        while (!T.empty()) {
            pair<char, int> p;
            p = T.top();
            s[p.second] = '0';
            T.pop();
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {} else {res += s[i];}
        }

        return res;

    }
};