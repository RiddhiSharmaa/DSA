class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total_elements = m * n;
        int cnt = 0;
        vector<int>ans;

        int startingRow = 0, startingCol = 0, endingRow = n-1, endingCol = m-1;

        while (cnt < total_elements){
            for (int i = startingCol; i <= endingCol && cnt < total_elements; i++){
                ans.push_back(matrix[startingRow][i]);
                cnt++;
            }
            startingRow++;

            for (int j = startingRow; j <= endingRow && cnt < total_elements; j++){
                ans.push_back(matrix[j][endingCol]);
                cnt++;
            }
            endingCol--;

            for (int i = endingCol; i >= startingCol && cnt < total_elements; i--){
                ans.push_back(matrix[endingRow][i]);
                cnt++;
            }
            endingRow--;

            for (int j = endingRow; j >= startingRow && cnt < total_elements; j--){
                ans.push_back(matrix[j][startingCol]);
                cnt++;
            }
            startingCol++;
        }

        return ans;
    }
};