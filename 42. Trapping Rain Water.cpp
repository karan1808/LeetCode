class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {return 0;}
        int nextmax[n];
        int premax[n];
        stack<int> nm;

        for (int i = n - 1; i >= 0; i--) {

            if (nm.empty()) {
                nextmax[i] = -1;
                nm.push(i);
            } else {

                while (!nm.empty() && height[i] >= height[nm.top()]) {
                    nm.pop();
                }

                if (nm.empty()) {
                    nextmax[i] = -1;
                    nm.push(i);
                } else {
                    nextmax[i] = nm.top();

                }



            }


        }

        stack<int> pm;

        for (int i = 0; i < n; i++) {

            if (pm.empty()) {
                premax[i] = -1;
                pm.push(i);
            } else {

                while (!pm.empty() && height[i] >= height[pm.top()]) {
                    pm.pop();
                }

                if (pm.empty()) {
                    premax[i] = -1;
                    pm.push(i);
                } else {
                    premax[i] = pm.top();

                }



            }


        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (nextmax[i] != -1 && premax[i] != -1) {res += (min(height[premax[i]], height[nextmax[i]]) - height[i]);}
        }

        return res;
    }
};