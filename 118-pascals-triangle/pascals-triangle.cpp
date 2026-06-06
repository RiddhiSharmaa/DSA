class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for (int i = 1; i <= numRows; i++){
            vector<int>row(i, 1);
            for (int j = 1; j < i-1; j++){
                if (i-2 >= 0 && j-1 >= 0) row[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(row);
        }

        return ans;
    }
};