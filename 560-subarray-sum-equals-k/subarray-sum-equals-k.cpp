class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int>mpp;
        mpp[0] = 1;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            int target = sum - k;

            if (mpp.find(target) != mpp.end()){
                cnt += mpp[target];
            }
            mpp[sum]++;
        }

        return cnt;
    }
};