class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }
        vector<int> v(101, 0);
        for (int i = 1; i <= 100; i++) {
            v[i] += v[i - 1];
            if (mp.find(i - 1) != mp.end()) {v[i] += mp[i - 1];}
        }
        vector<int>res;
        for (auto n : nums) {
            res.push_back(v[n]);
        }
        return res;
    }
};