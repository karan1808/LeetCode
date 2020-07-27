class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        map['W'] = map['Q'] = map['E'] = map['R'] = n / 4;

        for (auto ch : s) {
            map[ch]--;
        }

        unordered_map<char, int> extra;
        for (auto& p : map) {
            if (p.second < 0) {
                extra[p.first] = abs(p.second);
            }
        }

        if (extra.empty())
            return 0;

        int left = 0;
        int min_len = INT_MAX;
        int negative_vals = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (map[ch] < 0) {
                if (--extra[ch] == 0)
                    negative_vals++;
            }
            while (extra.size() - negative_vals == 0) {
                min_len = min(min_len, i - left + 1);
                char leftCh = s[left];
                if (map[leftCh] < 0) {
                    if (++extra[leftCh] == 1)
                        negative_vals--;
                }
                left++;
            }
        }
        return min_len;
    }
};