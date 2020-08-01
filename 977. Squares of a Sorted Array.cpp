class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1;
        vector<int> v;
        int rr, ll;
        while (r >= l) {
            A[r] = abs(A[r]);
            A[l] = abs(A[l]);
            // cout<<A[l]<<" "<<A[r]<<endl;
            if (A[r] > A[l]) {v.push_back(A[r]*A[r]); r--;} else {v.push_back(A[l]*A[l]); l++;}
        }
        reverse(v.begin(), v.end());
        return v;
    }
};