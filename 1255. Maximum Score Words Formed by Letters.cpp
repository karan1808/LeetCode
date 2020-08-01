class Solution {
    int res = 0;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> c(26, 0), used(26, 0);
        for (auto l : letters) {
            c[l - 'a']++;
        }
        backtrack(words, 0, used, c, score, 0);
        return res;
    }
    void backtrack(vector<string>& words, int start, vector<int>& used, vector<int>& c, vector<int>& score, int rew) {
        for (int i = 0; i < 26; i++) {
            if (used[i] > c[i]) {return;}
        }
        res = max(res, rew);
        for (int i = start; i < words.size(); i++) {
            for (auto x : words[i]) {
                used[x - 'a']++;
                rew += score[x - 'a'];
            }
            backtrack(words, i + 1, used, c, score, rew);

            for (auto x : words[i]) {
                used[x - 'a']--;
                rew -= score[x - 'a'];
            }
        }
    }
};