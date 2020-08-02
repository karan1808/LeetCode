class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int f = 0;
        int s = 0;
        int t = 0;
        int n = nums.size();
        if (n < 3) {return 0;}
        int res = nums[0] + nums[1] + nums[2];
        while (f < n - 2) {
            int y = nums[f];
            s = f + 1;
            t = n - 1;
            while (t > s) {
                int com = nums[f] + nums[s] + nums[t];
                if (abs(target - com) < abs(target - res)) {res = com;}
                if (nums[f] + nums[s] + nums[t] < target) {s++;} else {t--;}
            }
            f++;
        }
        return res;
    }
};