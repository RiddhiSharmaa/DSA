class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n);
        set<pair<int, int>>st;

        for (auto& r : roads){
            deg[r[0]]++;
            deg[r[1]]++;
            st.insert({min(r[0], r[1]), max(r[0], r[1])});
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int curr = deg[i] + deg[j];
                if (st.find({min(i, j), max(i, j)}) != st.end()) curr--;
                ans = max(ans, curr);
            }
        }

        return ans;
    }
};