class Solution {
public:
    using ll = long long;
    vector<int> findGoodIntegers(int n) {
        vector<int>ans;
        unordered_map<long long, int>mpp;
        unordered_set<int>st;

        for (ll i = 1; i*i*i <= n; i++){
            for (ll j = i; j*j*j <= n; j++){
                ll a = i*i*i;
                ll b = j*j*j;
                ll sum = a + b;
                if (sum > n) break;
                mpp[sum]++;
                if (mpp[sum] >= 2) {
                    if (st.find(sum) != st.end()) continue;
                    st.insert(sum);
                    ans.push_back(sum);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};