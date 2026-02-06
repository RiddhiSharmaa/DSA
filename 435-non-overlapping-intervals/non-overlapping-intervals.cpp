class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int cnt = 0;

        for (int i = 1; i < intervals.size(); i++){
            if (ans.back()[1] > intervals[i][0]){
                ans.back()[1] = min(ans.back()[1], intervals[i][1]);
                cnt++;
            } else if (ans.back()[1] <= intervals[i][0]){
                ans.push_back(intervals[i]);
            }
        }

        return cnt;
    }
};