class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;
        unordered_map<int, int>mpp;

        for (int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for (auto& [num, freq] : mpp){
            if (pq.size() == k){
                if (pq.top().first < freq){
                    pq.pop();
                } else {
                    continue;
                }
            }
            pq.push({freq, num});
        }

        vector<int>ans;

        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};