class Solution {
public:
    bool isSafe(int i, int j, vector<string>& ans){
        int n = ans.size();
        for (int r = 0; r < n; r++){
            if (ans[r][j] == 'Q') return false;
        }

        for (int c = 0; c < n; c++){
            if (ans[i][c] == 'Q') return false;
        }

        for (int r = i, c = j; r >= 0 && c >= 0; r--, c--){
            if (ans[r][c] == 'Q') return false;
        }

        for (int r = i, c = j; r >= 0 && c < n; r--, c++){
            if (ans[r][c] == 'Q') return false;
        }

        return true;
    }
    void helper(int i, vector<string>& ans, int& cnt){
        if (i == ans.size()) {
            cnt++;
            return;
        }

        for (int j = 0; j < ans.size(); j++){
            if (isSafe(i, j, ans)){
                ans[i][j] = 'Q';
                helper(i+1, ans, cnt);
                ans[i][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string>ans(n, string(n, '.'));
        helper(0, ans, cnt);

        return cnt;
    }
};