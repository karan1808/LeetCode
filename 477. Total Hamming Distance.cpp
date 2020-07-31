class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {return 0;}
        int tn = 0;
        int res = 0;
        while (true) {
            int z = 0;
            int o = 0;
            tn = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {tn++;}
                if (nums[i] % 2 == 0) {z++;} else {o++;}
                nums[i] = nums[i] >> 1;
            }
            res += z * o;
            if (tn == n) {return res;}
        }
    }
};