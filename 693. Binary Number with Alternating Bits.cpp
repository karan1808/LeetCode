class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n & 1;
        n >>= 1;
        int kl = 0;
        while (n > 0) {
            int y = n & 1;
            if (y == x) {kl++; break;} else {x = y;}
            n >>= 1;
        }
        if (kl == 0) {return true;} else {return false;}
    }
};