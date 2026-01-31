class Solution {
public:
    using ll = long long;
    int nonPositive(int n, vector<int>& nums){
        ll cnt = 0;
        for (int i = 0; i< nums.size(); i++){
            ll k = nums[i];
            cnt += (nums[i] + n -1)/ n;
        }

        return (int)cnt;
    }
    int minimumK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        ll low = 1, high = 1e9;
        
        while (low <= high){
            ll mid = low + (high - low)/2;
            ll a = nonPositive(mid, nums);

            if (a <= mid * mid){
                high = mid-1;
                
                ans = (int)mid;
            } else {
                low = mid+1;
            }
        
        }
        return ans;
    }  
};