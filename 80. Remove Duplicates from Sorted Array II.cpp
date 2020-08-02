class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st = 0;
        int ed = 0;
        int n = nums.size();
        int cu = 0;
        while (ed < n) {
            // cout<<ed<<" ed st "<<st<<endl;
            if (ed > 0) {
                if (nums[ed] == nums[ed - 1]) {cu++;} else {cu = 0;}
            }
            if (cu < 2) {
                int x = nums[ed];
                nums[st] = x;
                st++;
            }
            ed++;
        }
        // cout<<st<<" st "<<endl;
        return st;
    }
};