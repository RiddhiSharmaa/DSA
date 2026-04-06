class Solution {
public:
    using ll = __int128;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<ll>sum(n, 0);
        vector<ll>prod(n, -1);
        prod[n-1] = 1;
        for (int i = 1; i < n; i++){
            sum[i] = (ll)nums[i-1] + sum[i-1];
        }

        for (int i = 1; i < n; i++){
            sum[i] = (ll)nums[i-1] + sum[i-1];
            if (prod[n-i] > sum[n-i]) {
                break;
            } else {
                prod[n-i-1] = ((ll)nums[n-i]) * prod[n-i];
            }
        }

        for (int i = 0; i < n; i++){
            if (sum[i] == prod[i]) return i;
        }

        return -1;
    }
};