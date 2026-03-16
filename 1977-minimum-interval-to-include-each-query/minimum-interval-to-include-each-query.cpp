class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>ans(queries.size(), -1);
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>>q;

        for (int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;

        int j = 0;

        for (int i = 0; i < q.size(); i++){
            int query = q[i].first;

            while (j < intervals.size() && query >= intervals[j][0]){
                pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }

            while (!pq.empty() && query > pq.top().second){
                pq.pop();
            }

            if (!pq.empty()){
                ans[q[i].second] = pq.top().first;
            }
        }

        return ans;
    }
};