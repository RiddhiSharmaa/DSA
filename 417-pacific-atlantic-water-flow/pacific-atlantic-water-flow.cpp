class Solution {
public:
    void helper(int i, int j, vector<int>& row, vector<int>& col,
    vector<vector<int>>& reachesSea, vector<vector<int>>& heights){
        if (i >= heights.size() || j >= heights[i].size()) return;

        for (int k = 0; k < 4; k++){
            int r = i + row[k];
            int c = j + col[k];

            if (r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size() &&
            heights[r][c] >= heights[i][j] && reachesSea[r][c] != 1){
                reachesSea[r][c] = 1;
                helper(r, c, row, col, reachesSea, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>reachesPacific(n, vector<int>(m, 0));
        vector<vector<int>>reachesAtlantic(n, vector<int>(m, 0));
        vector<vector<int>>ans;

        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};

        for (int i = 0; i < n; i++){
            reachesPacific[i][0] = 1;
            reachesAtlantic[i][m-1] = 1;
            helper(i, 0, row, col, reachesPacific, heights);
            helper(i, m-1, row, col, reachesAtlantic, heights);
        }

        for (int j = 0; j < m; j++){
            reachesPacific[0][j] = 1;
            reachesAtlantic[n-1][j] = 1;
            helper(0, j, row, col, reachesPacific, heights);
            helper(n-1, j, row, col, reachesAtlantic, heights);
        }


        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (reachesPacific[i][j] && reachesAtlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};