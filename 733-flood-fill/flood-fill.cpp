class Solution {
public:
    void helper(int sr, int sc, int& originalColor, int &color, vector<int>row, 
    vector<int>& col, vector<vector<int>>& image){
        image[sr][sc] = color;

        for (int i = 0; i < row.size(); i++){
            int r = row[i] + sr;
            int c = col[i] + sc;

            if (r >= 0 && r < image.size() && c >= 0 && c < image[0].size() &&
            image[r][c] == originalColor){
                helper(r, c, originalColor, color, row, col, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};
        int originalColor = image[sr][sc];

        helper(sr, sc, originalColor, color, row, col, image);
        return image;
    }
};