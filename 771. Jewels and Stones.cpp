class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s;
        for (auto j : J) {
            s.insert(j);
        }
        int ans = 0;
        for (auto x : S) {
            if (s.find(x) != s.end()) {
                ans++;
            }
        }
        return ans;
    }
};