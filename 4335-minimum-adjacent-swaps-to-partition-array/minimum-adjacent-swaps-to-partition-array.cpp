class Solution {
public:
    int MOD = 1000000007;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int middleCnt = 0, endCnt = 0;
        long long cnt = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] < a){
                cnt += (middleCnt + endCnt) % MOD;
            } else if (nums[i] <= b){
                cnt += (endCnt) % MOD;
                middleCnt++;
            } else {
                endCnt++;
            }
        }

        return (int)(cnt % MOD);
    }
};