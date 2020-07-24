class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> T;

        int mxans = 0;

        for (int i = 0; i < n; i++) {

            if (T.empty()) {
                T.push(i);
            } else {

                if (heights[i] >= heights[T.top()]) {
                    T.push(i);
                } else {

                    while (!T.empty() && heights[i] < heights[T.top()]) {
                        int h = 0;
                        h = heights[T.top()];
                        if (!T.empty()) {T.pop();}
                        if (T.empty()) {mxans = max(mxans, h * (i));} else {

                            mxans = max(mxans, h * (i - (T.top()) - 1));
                        }
                    }
                    T.push(i);

                }



            }



        }
        while (!T.empty()) {
            int h = heights[T.top()];
            T.pop();
            if (T.empty()) {mxans = max(mxans, h * (n));} else {
                mxans = max(mxans, h * (n - T.top() - 1));
            }

        }

        return mxans;

    }
};