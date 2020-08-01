class Solution {
    string res = "";
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        if (n == 1) {return "1";}
        vector<int>factVal = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        fun(k, v, factVal, n);
        return res;
    }
    void fun(int k, vector<int>& v, vector<int>& factVal, int n) {

        if (n == 1) {
            res += to_string(v.back());
            return;
        }

        int index = (k / factVal[n - 1]);
        if (k % factVal[n - 1] == 0) {index--;}
        res += to_string(v[index]);
        v.erase(v.begin() + index);
        k -= factVal[n - 1] * index;
        fun(k, v, factVal, n - 1);

    }
};