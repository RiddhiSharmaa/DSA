class Solution {
public:
    int dp[50001];
    int helper(int i, vector<pair<pair<int, int>, int>>& jobs){
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int low = i;
        int high = jobs.size()-1;
        int ans = INT_MAX;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (jobs[mid].first.first >= jobs[i].first.second){
                ans = min(ans, mid);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        int take = jobs[i].second + helper(ans, jobs);
        int notTake = helper(i+1, jobs);
        return dp[i] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>>jobs;
        for (int i = 0; i < n; i++){
            jobs.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        memset(dp, -1, sizeof(dp));
        return helper(0, jobs);
    }
};