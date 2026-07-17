class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>diff(n, vector<int>(m, 1e9));
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};
        pq.push({0, {0, 0}});
        diff[0][0] = 0;

        while (!pq.empty()){
            int e = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n-1 && y == m-1) return e;

            for (int i = 0; i < 4; i++){
                int r = x + row[i];
                int c = y + col[i];
                if (r >= 0 && r < n && c >= 0 && c < m){
                    int difference = max(abs(heights[x][y] - heights[r][c]), e);
                    if (difference < diff[r][c]){
                        diff[r][c] = difference;
                        pq.push({difference, {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};