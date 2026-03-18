class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size(), m = triplets[0].size();
        bool a = false, b = false, c = false;

        for (int i = 0; i < n; i++){
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || 
            triplets[i][2] > target[2]) continue;

            if (triplets[i][0] == target[0]) a = true;
            if (triplets[i][1] == target[1]) b = true;
            if (triplets[i][2] == target[2]) c = true;
        }

        return (a == b && b == c && a == true) ? true : false;
    }
};