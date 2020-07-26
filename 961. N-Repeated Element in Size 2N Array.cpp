class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> mp;
        int tar = A.size() / 2;
        int res = 0;
        for (auto a : A) {
            mp[a]++;
            if (mp[a] >= tar) {return a;}
        }
        return 0;
    }
};