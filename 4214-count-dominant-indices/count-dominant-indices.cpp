class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt  = 0;
        double sum = 0;
        int k = 0;
        for (int i = 1; i < nums.size(); i++){
            sum += nums[i];
        }

        for (int i = 1; i < nums.size(); i++){
            double s = sum/(double)(nums.size()-i);
            if (s < nums[i-1]){
                cnt++;
            }
            sum -= nums[i];
        }

        return cnt;
    }
};