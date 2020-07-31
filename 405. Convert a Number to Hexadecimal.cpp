class Solution {
public:
    string toHex(int num) {
        if (num == 0) {return "0";}
        if (num < 0) {
            long long y = 1;
            y <<= 32;
            long long x = (y) + num;
            // cout<<x<<endl;
            string s = "";

            while (x != 0) {
                int r = x % 16;
                x /= 16;
                char c = '0';
                if (r < 10) {c = (c + r);}
                if (r == 10) {c = 'a';}
                if (r == 11) {c = 'b';}
                if (r == 12) {c = 'c';}
                if (r == 13) {c = 'd';}
                if (r == 14) {c = 'e';}
                if (r == 15) {c = 'f';}
                s = c + s;
            }

            return s;

        } else {
            int x = num;

            string s = "";

            while (x != 0) {
                int r = x % 16;
                x /= 16;
                char c = '0';
                if (r < 10) {c = (c + r);}
                if (r == 10) {c = 'a';}
                if (r == 11) {c = 'b';}
                if (r == 12) {c = 'c';}
                if (r == 13) {c = 'd';}
                if (r == 14) {c = 'e';}
                if (r == 15) {c = 'f';}
                s = c + s;
            }

            return s;
        }
    }
};