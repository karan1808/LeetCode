class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int numx = 0;
        for (auto n : nums) {
            numx ^= n;
        }
        int lastbit = (numx & (numx - 1))^numx;
        int x = 0;
        int y = 0;
        for (auto n : nums) {
            if ((lastbit & n) == 0) {
                x ^= n;
            } else {
                y ^= n;
            }
        }
        return {x, y};
    }
};