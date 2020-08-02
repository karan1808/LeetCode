class Solution {
    vector<vector<int>> v;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }
        vector<int> r;
        int n = nums.size();
        backtrack(r, mp, n);
        return v;
    }
    void backtrack(vector<int>& r, unordered_map<int, int>& mp, int n) {
        if (r.size() == n) {v.push_back(r); return;}
        for (auto it : mp) {
            if (it.second > 0) {
                r.push_back(it.first);
                mp[it.first]--;
                backtrack(r, mp, n);
                mp[it.first]++;
                r.pop_back();
            }
        }
    }

};