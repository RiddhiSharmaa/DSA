class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++){
            int cnt = 0;
            while (nums[i] > 0){
                int d = nums[i]%10;
                if (d == digit) cnt++;
                nums[i] /= 10;
            }
            ans += cnt;
        }

        return ans;
    }
};