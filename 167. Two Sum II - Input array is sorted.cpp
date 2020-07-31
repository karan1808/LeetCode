class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        int i = 1;
        int x = 0; int y = 0;
        for (auto n : numbers) {
            if (mp.find(target - n) != mp.end()) {
                x = mp[target - n];
                y = i;
                break;
            } else {
                mp[n] = i;
            }
            i++;
        }
        return {x, y};
    }
};