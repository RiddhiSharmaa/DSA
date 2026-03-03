class Solution {
public:
    int helper(int i, int currXor, vector<int>& nums){
        if (i >= nums.size()) return currXor;
        
        return helper(i+1, currXor ^ nums[i], nums) + 
        helper(i+1, currXor, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        return helper(0, 0, nums);
    }
};