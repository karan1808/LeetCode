class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> mp;
        mp[0]++;
        int n = A.size();
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (mp.find(sum - S) != mp.end()) {res += mp[sum - S];}
            mp[sum]++;
        }

        return res;
    }
};