class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>inDegree(n, 0);
        vector<int>imp(n, 0);
        long long ans = 0;

        for (auto& e : roads){
            inDegree[e[1]]++;
            inDegree[e[0]]++;
        }

        priority_queue<pair<int, int>>pq;
        for (int i = 0; i < n; i++){
            pq.push({inDegree[i], i});
        }

        while(!pq.empty()){
            int num = pq.top().second;
            imp[num] = n;
            n--;
            pq.pop();
        }

        for (auto& e : roads){
            ans += (imp[e[0]] + imp[e[1]]);
        }

        return ans;
    }
};