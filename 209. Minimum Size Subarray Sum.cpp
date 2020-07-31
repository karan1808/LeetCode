class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int res = INT_MAX;
        int fast = 0;
        int slow = 0;
        int n = nums.size();
        while (slow < n && fast < n) {
            while (fast < n && sum < s) {
                sum += nums[fast];
                fast++;
            }
            while (sum >= s) {
                res = min(res, fast - slow);
                sum -= nums[slow];
                slow++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};