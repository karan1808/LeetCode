class Solution {
public:
    int calculate(string s) {
        stack<int> T;
        long long num = 0;
        int sign = 1;
        int ans = 0;

        for (auto c : s) {

            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else {



                if (c == '+') {
                    ans += (num * sign);
                    sign = 1;
                    num = 0;
                }

                if (c == '-') {
                    ans += (num * sign);
                    sign = -1;
                    num = 0;
                }

                if (c == '(') {
                    T.push(ans);
                    ans = 0;
                    T.push(sign);
                    sign = 1;
                }

                if (c == ')') {
                    ans += sign * num;
                    ans = ans * T.top();
                    T.pop();
                    ans += T.top();
                    T.pop();
                    sign = 1;
                    num = 0;
                }

            }



        }
        ans += num * sign;
        return ans;

    }
};