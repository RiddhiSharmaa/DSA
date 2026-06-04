class Solution {
public:      
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>pq;

        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if (x == n-1 && y == m-1) return t;

            for (int i = 0; i < 4; i++){
                int r = row[i] + x;
                int c = col[i] + y;

                if (r >= 0 && r < n && c >= 0 && c < m){
                    int a = 0;
                    if (t <= moveTime[r][c]){
                        a = moveTime[r][c] + 1;
                    } else {
                        a = t + 1;
                    }
                    if (dist[r][c] > a){
                        dist[r][c] = a;
                        pq.push({dist[r][c], {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};