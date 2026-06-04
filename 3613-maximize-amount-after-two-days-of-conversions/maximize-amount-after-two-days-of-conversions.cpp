class Solution {
public:
    unordered_map<string, double>helper(string src, 
    unordered_map<string, vector<pair<string, double>>>& mpp){
        unordered_map<string, double>cost;
        queue<string>q;
        q.push(src);
        cost[src] = 1.0;

        while (!q.empty()){
            string cur = q.front();
            q.pop();

            for (auto& [c, r] : mpp[cur]){
                if (cost.find(c) == cost.end()){
                    cost[c] = cost[cur] * r;
                    q.push(c);
                }
            }
        }

        return cost;
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>>mpp, mpp2;

        for (int i = 0; i < pairs1.size(); i++){
            auto& e = pairs1[i];
            mpp[e[0]].push_back({e[1], rates1[i]});
            mpp[e[1]].push_back({e[0], 1.0/rates1[i]});
        }

        for (int i = 0; i < pairs2.size(); i++){
            auto& e = pairs2[i];
            mpp2[e[0]].push_back({e[1], rates2[i]});
            mpp2[e[1]].push_back({e[0], 1.0/rates2[i]});
        }

        auto day1 = helper(initialCurrency, mpp);
        double ans = 1.0;

        for (auto& [currency, rate] : day1){
            auto day2 = helper(currency, mpp2);

            if (day2.find(initialCurrency) != day2.end()){
                ans = max(ans, day1[currency] * day2[initialCurrency]);
            }
        }

        return ans;
    }
};