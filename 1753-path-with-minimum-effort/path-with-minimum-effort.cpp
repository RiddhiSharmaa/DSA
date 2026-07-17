class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};
        pq.push({0, {0, 0}});
        int effort = 0;

        while (!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (vis[x][y]) continue;
            vis[x][y] = 1;
            effort = max(effort, d);
            if (x == n-1 && y == m-1) break;

            for (int i = 0; i < 4; i++){
                int r = x + row[i];
                int c = y + col[i];
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]){
                    int diff = abs(heights[x][y] - heights[r][c]);
                    pq.push({diff, {r, c}});
                }
            }
        }

        return effort;
    }
};