class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>visited(n, vector<int>(n, 0));
        vector<vector<int>>time(n, vector<int>(n, 1e9));
        priority_queue<P, vector<P>, greater<P>>pq;

        vector<int>rows = {-1, 0, 1, 0};
        vector<int>cols = {0, 1, 0 , -1};

        pq.push({grid[0][0], {0, 0}});
        time[0][0] = grid[0][0];

        while (!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int t = pq.top().first;
            pq.pop();

            if (x == n-1 && y == n-1) return t;
            if (visited[x][y]) continue;
            visited[x][y] = 1;

            for (int i = 0; i < 4; i++){
                int r = x + rows[i];
                int c = y + cols[i];

                if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]){
                    int maxTime = max(t, grid[r][c]);
                    if (maxTime < time[r][c]){
                        time[r][c] = maxTime;
                        pq.push({maxTime, {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};