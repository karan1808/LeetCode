class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int k = K;
        int st = 0;
        int n = A.size();
        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
            if (mp.size() <= k) {ans1 += i + 1 - st; continue;}
            while (mp.size() > k) {
                mp[A[st]]--;
                if (mp[A[st]] == 0) {mp.erase(A[st]);}
                st++;
            }
            ans1 += i + 1 - st;
        }

        unordered_map<int, int> mp2;
        k = K - 1;
        st = 0;
        n = A.size();
        int ans2 = 0;
        for (int i = 0; i < n; i++) {
            mp2[A[i]]++;
            if (mp2.size() <= k) {ans2 += i + 1 - st; continue;}
            while (mp2.size() > k) {
                mp2[A[st]]--;
                if (mp2[A[st]] == 0) {mp2.erase(A[st]);}
                st++;
            }
            ans2 += i + 1 - st;
        }

        return ans1 - ans2;



    }
};