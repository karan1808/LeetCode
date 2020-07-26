class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mpt;
        unordered_map<char, int> mps;

        for (auto x : t) {
            mpt[x]++;
        }
        int n = s.size();
        if (n == 0) {return "";}
        int ans = INT_MAX;
        int m = t.size();
        if (m == 0) {return "";}
        int yo = 0;
        int st = 0;
        int kl = 0;
        for (int i = 0; i < n; i++) {

            if (mpt.find(s[i]) != mpt.end()) {

                if (mps[s[i]] < mpt[s[i]]) {
                    yo++;
                }
                mps[s[i]]++;
                // cout<<yo<<" yo "<<i<<endl;
                while (yo == m) {
                    // cout<<i<<" i "<<endl;
                    // cout<<st<<" st i "<<i<<endl;
                    if (i - st < ans) {
                        ans = min(ans, i - st);
                        kl = st;
                    }
                    mps[s[st]]--;
                    if (mpt.find(s[st]) != mpt.end()) {
                        if (mps[s[st]] < mpt[s[st]]) {yo--; st++;} else {st++;}
                    } else {st++;}
                }
            } else {mps[s[i]]++;}


        }
        string res = "";
        if (ans == INT_MAX) {return res;}
        for (int i = kl; i <= kl + ans; i++) {
            res += s[i];
        }
        return res;
    }
};