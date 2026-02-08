class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left = 0, cost = 0, cnt = 0;
        map<long long, long long>mpp;

        for (long long right = 0; right < nums.size(); right++){
            mpp[nums[right]]++;

            cost = (mpp.rbegin()->first - mpp.begin()->first)*(right-left+1);

            while (cost > k){
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                } 
                left++;
                cost = (mpp.rbegin()->first - mpp.begin()->first)*(right-left+1);
            }
            
            if (cost <= k) {
                cnt += (right-left+1);
            }
        }

        return cnt;
    }
};