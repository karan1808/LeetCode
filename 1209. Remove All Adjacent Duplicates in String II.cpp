class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) return s;
        stack<pair<char, int>> T;
        for (int i = 0; i < s.length(); i++) {
            if (!T.empty() && T.top().first == s[i]) {
                if (T.top().second == k - 1) T.pop();
                else T.top().second++;
            } else {
                T.push(make_pair(s[i], 1));
            }
        }
        s = "";
        while (!T.empty()) {
            int count = T.top().second;
            while (count > 0) {
                s = T.top().first + s;
                count--;
            }
            T.pop();
        }
        return s;

    }
};