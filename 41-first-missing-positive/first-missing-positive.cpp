class Solution {
public:
    using ll = long long;
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        ll maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            maxi = max(maxi, (ll)nums[i]);
        }

        for (ll i = 1; i <= maxi + 1; i++){
            if (st.find(i) == st.end()) return (int)i;
        }

        return 1;
    }
};