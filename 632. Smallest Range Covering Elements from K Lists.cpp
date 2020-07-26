class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();

        vector<int>res(2);

        vector<int>ps(n, 0);

        int misi = INT_MAX;

        vector<int>sz(n, 0);
        int i = 0;
        for (auto v : nums) {sz[i] = v.size(); i++;}

        set<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            st.insert(make_pair(nums[i][0], i));
        }

        while (true) {

            pair<int, int> sm = *st.begin();
            pair<int, int> lm = *st.rbegin();

            if ((lm.first - sm.first + 1) < misi) {
                misi = lm.first - sm.first + 1;
                res[0] = sm.first;
                res[1] = lm.first;
            }
            int smli = sm.second;
            ps[smli]++;
            if (ps[smli] < sz[smli]) {
            } else {break;}

            st.erase(st.begin());
            st.insert(make_pair(nums[smli][ps[smli]], smli));
        }

        return res;

    }
};