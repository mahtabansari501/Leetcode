
class Solution {
public:
    bool solve(vector<vector<char>>& board, int idx) {
        if(idx == 81) return true;
        int row = idx / 9;
        int col = idx % 9;
        if(board[row][col] == '.') {
            return solve(board, idx + 1);
        }

        char ch = board[row][col];
        for(int i = 0; i < 9; i++) {

            if(i != col && board[row][i] == ch)
                return false;

            if(i != row && board[i][col] == ch)
                return false;
        }
        int sr = 3 * (row / 3);
        int sc = 3 * (col / 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                int r = sr + i;
                int c = sc + j;

                if((r != row || c != col) && board[r][c] == ch)
                    return false;
            }
        }

        return solve(board, idx + 1);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board, 0);
    }
};
