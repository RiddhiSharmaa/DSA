class Solution {
public:
    bool isSafe(int i, int j, vector<vector<char>>& board){
        for (int k = i; k >= 0; k--){
            if (board[k][j] == 'Q') return false;
        }

        int r = i, c = j;
        while (r >= 0 && c >= 0){
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = i, c = j;
        while (r >= 0 && c < board.size()){
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }
    void helper(int i, int& cnt, vector<vector<char>>& board){
        if (i == board.size()){
            cnt++;
            return;
        }

        for (int j = 0; j < board.size(); j++){
            if (isSafe(i, j, board)){
                board[i][j] = 'Q';
                helper(i+1, cnt, board);
                board[i][j] = ',';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>>board(n, vector<char>(n, ','));
        int cnt = 0;
        helper(0, cnt, board);

        return cnt;
    }
};