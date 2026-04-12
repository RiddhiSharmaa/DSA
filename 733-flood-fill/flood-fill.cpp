class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};
        int originalColor = image[sr][sc];
        queue<pair<int, int>>q;
        q.push({sr, sc});

        while (!q.empty()){
            auto p = q.front();
            q.pop();
            int nrow = p.first;
            int ncol = p.second;
            image[nrow][ncol] = color;

            for (int i = 0; i < row.size(); i++){
                int r = row[i] + nrow;
                int c = col[i] + ncol;

                if (r >= 0 && r < image.size() && c >= 0 && c < image[0].size() &&
                image[r][c] == originalColor){
                    q.push({r, c});
                }
            }
        }

        return image;
    }
};