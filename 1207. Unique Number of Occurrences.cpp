class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto a : arr) {
            mp[a]++;
        }
        set<int> s;
        for (auto it : mp) {
            int x = it.second;
            if (s.find(x) != s.end()) {return false;}
            s.insert(x);
        }
        return true;
    }
};