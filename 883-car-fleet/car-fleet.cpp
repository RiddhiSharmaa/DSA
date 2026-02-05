class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), cnt = 0; 
        double maxTime = -1.0;
        vector<vector<int>>combined;
        for (int i = 0; i < n; i++){
            combined.push_back({position[i], speed[i]});
        }

        sort(combined.rbegin(), combined.rend());

        for (int i = 0; i < n; i++){
            int dist = target - combined[i][0];
            double time = (double)dist/combined[i][1];
            if (time > maxTime){
                maxTime = time;
                cnt++;
            }
        }

        return cnt;
    }
};