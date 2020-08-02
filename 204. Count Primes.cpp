class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ch(n + 1, true);
        ch[0] = false;
        ch[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (ch[i] == false)continue;

            int j = i * i;
            while (j <= n) {
                ch[j] = false;
                j += i;
            }
        }
        int count = 0;
        for (int i = 1; i < n; i++)
            if (ch[i]) count++;

        return count;
    }
};