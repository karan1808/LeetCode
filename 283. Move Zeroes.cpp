class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int ed = 0;
        int n = nums.size();
        while (ed < n) {
            if (nums[ed] == 0) {
            } else {
                nums[st] = nums[ed];
                st++;
            }
            ed++;
        }
        while (st < n) {
            nums[st] = 0;
            st++;
        }
    }
};