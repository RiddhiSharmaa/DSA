class Solution {
public:
    bool helper(int l, int i, int j, vector<int>& row, vector<int>& col, 
    vector<vector<char>>& board, string& word, vector<vector<int>>& visited){
        if (l == word.size()-1) return true;
        visited[i][j] = 1;

        for (int k = 0; k < 4; k++){
            int r = row[k] + i;
            int c = col[k] + j;
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() &&
            l+1 < word.size() && board[r][c] == word[l+1] && !visited[r][c]){
                if (helper(l+1, r, c, row, col, board, word, visited)) return true;
            }
        }

        visited[i][j] = 0;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (word[0] == board[i][j]){
                    if (helper(0, i, j, row, col, board, word, visited)) return true;
                }
            }
        }

        return false;
    }
};