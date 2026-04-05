class Solution {
public:
    using ll = long long;
    vector<int> findGoodIntegers(int n) {
        vector<int>ans;
        unordered_map<int, int>mpp;

        for (ll i = 1; i*i*i <= n; i++){
            for (ll j = i; j*j*j<= n; j++){
                ll a = i*i*i;
                ll b = j*j*j;
                ll sum = a + b;
                if (sum > n) break;
                mpp[sum]++;
            }
        }

        for (auto [num, freq] : mpp){
            if (freq >= 2) ans.push_back(num);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};