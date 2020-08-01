class Solution {
public:
    unordered_map<int, int> s;
    vector<int> ans;
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<vector<int>> p(26);
        const int N = words.size();
        const int M = puzzles.size();
        for (int i = 0; i < N; ++i)
        {
            int k = 0;
            for (int j = 0; j < words[i].size(); ++j)
            {
                if ((k & (1 << (words[i][j] - 'a'))) == 0)
                {
                    k = (k | (1 << (words[i][j] - 'a')));
                }
            }
            s[k]++;
            // cout<<k<<" k "<<endl;
        }

        for (int i = 0; i < M; i++) {
            int y = (1 << (puzzles[i][0] - 'a'));
            // cout<<y<<" y "<<endl;
            vector<int> yo;
            yo.push_back(y);
            backtrack(1, puzzles[i], y, yo);
            sort(yo.begin(), yo.end());
            int kl = yo[0];
            int co = 0;
            for (int z = 0; z < yo.size(); z++) {
                // cout<<yo[z]<<endl;
            }
            if (s.find(kl) != s.end()) {co += s[kl];}
            for (int z = 1; z < yo.size(); z++) {
                if (yo[z] != yo[z - 1]) {
                    int kl = yo[z];
                    if (s.find(kl) != s.end()) {co += s[kl];}
                }
            }
            ans.push_back(co);
        }

        return ans;
    }
    void backtrack(int st, string& s, int sum, vector<int>& yo) {
        if (st == s.size()) {
            yo.push_back(sum);
        }
        for (int i = st; i < s.size(); i++) {
            sum = (sum + (1 << (s[i] - 'a')));
            backtrack(i + 1, s, sum, yo);
            sum = (sum - (1 << (s[i] - 'a')));
            if (i + 1 == s.size()) {backtrack(i + 1, s, sum, yo);}
        }
    }
};