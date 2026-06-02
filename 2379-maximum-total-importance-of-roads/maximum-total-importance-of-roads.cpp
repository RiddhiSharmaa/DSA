class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>inDegree(n, 0);
        long long ans = 0;

        for (auto& e : roads){
            inDegree[e[1]]++;
            inDegree[e[0]]++;
        }

        sort(inDegree.rbegin(), inDegree.rend());

        int limit = n;
        for (int i = 0; i < n; i++){
            ans += (inDegree[i] * limit);
            limit--;
        }

        return ans;
    }
};