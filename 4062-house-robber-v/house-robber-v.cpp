class Solution {
public:
    using ll = long long;
    long long helper(int i, vector<int>& nums, vector<int>& colors, vector<ll>& dp){
        
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        long long choice1 = 0, choice2 = 0;
        
        choice1 += helper(i+1, nums, colors, dp);
        if (i+1 < nums.size() && colors[i] == colors[i+1]){
            choice2 += nums[i] + helper(i+2, nums,colors, dp);
        } else {
            choice2 += nums[i] + helper(i+1, nums, colors, dp);
        }

        return dp[i] = max(choice1, choice2);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<ll>dp(n+1, -1);

        return helper(0, nums, colors, dp);
    }
};

// class Solution {
// public:
//     long long helper(int i, int j, vector<int>& nums, 
//         vector<int>& colors, vector<int>& dp){
        
//         if (i >= nums.size()) return 0;

//         if (dp[i] != -1) return dp[i];

//         long long choice1 = 0, choice2 = 0;
//         if (j == 1){
//             if (i-1 >= 0 && colors[i] == colors[i-1]){
//                 choice1 += 0 + helper(i+1, !j, nums, colors, dp);
//             } else {
//                 choice1 += nums[i] + helper(i+1, j, nums, colors, dp);
//             }
//         }
        
//         if (j == 0 || colors[i] != colors[i-1]){
//             choice2 += nums[i] + helper(i+1, !j, nums, colors, dp);
//         } 
            

//         return dp[i] = max(choice1, choice2);
//     }
//     long long rob(vector<int>& nums, vector<int>& colors) {
//         int n = nums.size();
//         vector<vecint>dp(n, -1);

//         return max(helper(0, 0, nums, colors, dp), helper(1, 0, nums, colors, dp));
//     }
// };