class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> mp;
        set<int> dd;
        vector<int> ans;
        int n = rains.size();
        for (int i = 0; i < n; i++) {

            if (rains[i] == 0) {
                dd.insert(i);
                ans.push_back(1);
            } else {

                int y = rains[i];
                if (mp.find(y) != mp.end()) {
                    auto it = dd.lower_bound(mp[y]);
                    if (it == dd.end()) {
                        return {};
                    } else {
                        int kl = *it;
                        ans[kl] = y;
                        dd.erase(kl);
                    }


                }
                mp[y] = i;
                ans.push_back(-1);


            }

        }
        return ans;


    }
};