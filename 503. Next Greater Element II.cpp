class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        stack<int> stack;
        vector<int> res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (stack.size() && A[stack.top()] < A[i % n]) {
                res[stack.top()] = A[i % n];
                stack.pop();
            }
            stack.push(i % n);
        }
        return res;
    }
};