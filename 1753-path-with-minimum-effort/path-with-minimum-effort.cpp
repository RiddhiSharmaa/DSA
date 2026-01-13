class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<vector<int>>diff(n, vector<int>(m, 1e9));
        priority_queue<P, vector<P>, greater<P>>pq;

        vector<int> rows = {-1, 0, 1, 0};
        vector<int> cols = {0, 1, 0, -1};

        pq.push({heights[0][0], {0, 0}});
        diff[0][0] = heights[0][0];

        if (n > 1 && m == 1){
            diff[0][0] = abs(heights[0][0] - heights[1][0]);
            pq.push({diff[0][0], {0, 0}});
        } else if (n == 1 && m > 1){
            diff[0][0] = abs(heights[0][0] - heights[0][1]);
            pq.push({diff[0][0], {0, 0}});
        } else if (n > 1 && m > 1) {
            diff[0][0] = min(abs(heights[0][0] - heights[0][1]),
            abs(heights[0][0] - heights[1][0]));
            pq.push({abs(heights[0][0] - heights[0][1]), {0, 0}});
            pq.push({abs(heights[0][1] - heights[0][1]), {0, 0}});
        } else if (n == 1 && m == 1){
            return 0;
        }

        while (!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            if (x == n-1 && y == m-1) return effort;
            if (visited[x][y]) continue;
            visited[x][y] = 1;

            for (int i = 0; i < 4; i++){
                int r = rows[i] + x;
                int c = cols[i] + y;

                if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]){
                    int currMin = max(abs(heights[r][c] - heights[x][y]), effort);
                    if (currMin < diff[r][c]){
                        diff[r][c] = currMin;
                        pq.push({currMin, {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};