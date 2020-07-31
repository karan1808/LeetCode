class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cou = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == major) {cou++;} else {
                cou--;
                if (cou == 0) {major = nums[i]; cou++;}
            }
        }
        return major;
    }
};