class Solution {
public:
    using ll = long long;
    int minimumK(vector<int>& nums) {
        int ans = -1;
        ll low = 1, high = 1e5;
        
        while (low <= high){
            ll mid = low + (high - low)/2;
            ll oper = 0;

            for (int num : nums){
                oper += (num + mid - 1) / mid;
            }

            if (oper <= mid * mid){
                high = mid-1;
                ans = (int)mid;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }  
};