class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<long> vu(n);
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (auto c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            vu[i] = mask;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int v1 = vu[i];
                int v2 = vu[j];
                if ((v1 & v2) == 0) {
                    int le = words[i].size() * words[j].size();
                    if (le > res) {res = le;}
                }
            }
        }
        return res;
    }
};