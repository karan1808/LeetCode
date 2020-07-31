class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        for (auto s : s1) {v1[(int)(s - 'a')]++;}
        int n1 = s1.size();
        vector<int> v2(26, 0);
        int n2 = s2.size();
        if (n1 > n2) {return 0;} else {
            int res = 0;
            for (int i = 0; i < n1; i++) {
                v2[(int)(s2[i] - 'a')]++;
            }
            if (v1 == v2) {res++;}
            for (int i = n1; i < n2; i++) {
                v2[(int)(s2[i] - 'a')]++;
                v2[(int)(s2[i - n1] - 'a')]--;
                if (v1 == v2) {res++;}
            }
            return res;
        }
    }
};