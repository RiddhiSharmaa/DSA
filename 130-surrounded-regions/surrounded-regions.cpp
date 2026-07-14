class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    void helper(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        board[i][j] = 'C';
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++){
            int r = dr[k] + i;
            int c = dc[k] + j;
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() &&
            board[r][c] == 'O' && !vis[r][c]){
                helper(r, c, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++){
            if (board[i][0] == 'O' && !vis[i][0]){
                helper(i, 0, board, vis);
            }
            if (board[i][m-1] == 'O' && !vis[i][m-1]){
                helper(i, m-1, board, vis);
            }
        }

        for (int j = 0; j < m; j++){
            if (board[0][j] == 'O' && !vis[0][j]){
                helper(0, j, board, vis);
            }
            if (board[n-1][j] == 'O' && !vis[n-1][j]){
                helper(n-1, j, board, vis);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};