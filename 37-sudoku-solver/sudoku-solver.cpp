class Solution {
public:
    bool canPlace(int i, int j, int k, vector<vector<char>>& board){
        for (int r = 0; r < 9; r++){
            if (board[i][r] == k + '0' || board[r][j] == k + '0') return false;
        }
        int startRow = (i/3)*3;
        int startCol = (j/3)*3;

        for (int r = startRow; r < startRow + 3; r++){
            for (int c = startCol; c < startCol + 3; c++){
                if (board[r][c] == k + '0') return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    for (int k = 1; k <= 9; k++){
                        if (canPlace(i, j, k, board)){
                            board[i][j] = k + '0';
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};