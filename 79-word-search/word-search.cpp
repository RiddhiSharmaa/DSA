class Solution {
public:
    bool helper(int i, int j, int idx, vector<vector<char>>& board, string& word,
    vector<int>& nrow, vector<int>& ncol, vector<vector<int>>& visited){
        if (idx == word.size()-1){
            if (board[i][j] == word[idx]){
                return true;
            } else {
                return false;
            }
        }
        if (visited[i][j] == 1 || idx >= word.size()){
            return false;
        }
        if (board[i][j] != word[idx]) return false;

        visited[i][j] = 1;

        for (int r = 0; r < nrow.size(); r++){
            int row = i + nrow[r];
            int col = j + ncol[r];
            if (row >= 0 && col >= 0 && row < board.size() && col < board[0].size()
            && visited[row][col] == 0){
                if (helper(row, col, idx+1, board, word, nrow, ncol, visited)){
                    return true;
                }
            }
        }
        
        visited[i][j] = 0;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<int>nrow = {-1, 0, 1, 0};
        vector<int>ncol = {0, 1, 0, -1};
        vector<vector<int>>visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0]){
                    if (helper(i, j, 0, board, word, nrow, ncol, visited)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};