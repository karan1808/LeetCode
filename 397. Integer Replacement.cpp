class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        while (n > 1) {
            if (n == 3) {return res + 2;}
            if (n == INT_MAX)
                return 32;
            res++;
            if (n % 2 == 0) {n /= 2; continue;}
            if ((n + 1) % 4 == 0) {
                n++;
            } else {n--;}

        }
        return res;
    }
};