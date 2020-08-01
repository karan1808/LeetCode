class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {return true;}
        if (j == 9) {return solve(board, i + 1, 0);}

        if (board[i][j] != '.') {return solve(board, i, j + 1);} else {
            for (char c = '1'; c <= '9'; c++) {
                if (check(board, i, j, c)) {
                    board[i][j] = c;
                    if (solve(board, i, j + 1)) return true;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int i, int j, char& c) {

        int col = j - j % 3;
        int row = i - i % 3;
        for (int y = 0; y < 9; y++) {
            if (board[i][y] == c) {return false;}
        }
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == c) {return false;}
        }
        for (int x = row; x < row + 3; x++) {
            for (int y = col; y < col + 3; y++) {
                if (board[x][y] == c) {return false;}
            }
        }
        return true;
    }
};