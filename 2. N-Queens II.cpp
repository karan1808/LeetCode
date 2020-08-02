class Solution {
    vector<vector<string>> res;
public:
    int totalNQueens(int n) {
        vector<string> c(n, string(n, '.'));

        backtrack(c, 0, n);
        return res.size();
    }
    void backtrack(vector<string>& c, int i, int n) {
        if (i == n) {res.push_back(c); return;}

        for (int col = 0; col < n; col++) {
            if (vaild(c, i, col, n)) {
                c[i][col] = 'Q';
                backtrack(c, i + 1, n);
                c[i][col] = '.';
            }
        }
    }
    bool vaild(vector<string>& c, int row, int col, int n) {
        for (int i = 0; i != row; ++i)
            if (c[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (c[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (c[i][j] == 'Q')
                return false;
        return true;
    }
};