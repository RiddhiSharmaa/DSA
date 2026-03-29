class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        int cnt = 0;
        mpp[0] = 1;
    
        int currSum = 0;
        for (int i = 0; i < n; i++){
            currSum += nums[i];
            int complement = currSum - k;
            if (mpp.find(complement) != mpp.end()){
                cnt += mpp[complement];
            }
            mpp[currSum]++;
        }

        return cnt;
    }
};