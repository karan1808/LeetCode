class Solution {
public:
    static bool compare(int a, int b) {
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), compare);
        unordered_map<int, int> mp;
        for (auto a : A) {
            mp[a]++;
        }
        for (auto a : A) {
            if (mp[a] == 0) {continue;}
            if (mp[2 * a] == 0) {return false;}
            mp[2 * a]--; mp[a]--;
        }


        return true;
    }
};