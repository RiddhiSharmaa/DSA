class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>degree(matrix.size(), 0);

        for (int i = 0; i < matrix.size(); i++){
            for (int j = i; j < matrix[0].size(); j++){
                if (matrix[i][j] == 1){
                    degree[i]++;
                    degree[j]++;
                }
            }
        }

        return degree;
    }
};