class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);

        if (rooms[0].size() == 0){
            return false;
        }

        queue<int>q;
        visited[0] = 1;
        q.push(0);

        while(!q.empty()){
            int room = q.front();
            q.pop();

            for (int& n : rooms[room]){
                if (!visited[n]){
                    visited[n] = true;
                    q.push(n);
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (visited[i] == 0) return false;
        }

        return true;
    }
};