class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        for (auto& e : edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for (int via = 0; via < n; via++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][via] + dist[via][j] < dist[i][j]){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }

        int ans = 0;
        int minCnt = INT_MAX;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (j == i) continue;
                if (dist[i][j] <= k){
                    cnt++;
                }
            }
            if (cnt <= minCnt){
                minCnt = cnt;
                ans = i;
            }
        }

        return ans;
    }
};