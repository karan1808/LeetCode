class Solution {
public:
    int findComplement(int num) {
        long long x = 1;
        int cou = 0;
        int n = num;
        while (n > 0) {
            cou++;
            n >>= 1;
        }
        x = x << (cou);
        x--;
        return (x - num);
    }
};