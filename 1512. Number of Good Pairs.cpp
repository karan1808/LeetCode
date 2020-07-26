class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto nu : nums) {
            if (mp.find(nu) != mp.end()) {
                res += mp[nu];
            }
            mp[nu]++;
        }
        return res;
    }
};