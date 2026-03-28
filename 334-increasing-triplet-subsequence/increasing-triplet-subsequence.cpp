class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> mini(n, INT_MAX), maxi(n, INT_MIN);

        mini[0] = nums[0];
        maxi[n-1] = nums[n-1];

        for (int i = 1; i < n; i++){
            mini[i] = min(mini[i-1], nums[i-1]);
            maxi[n-i-1] = max(maxi[n-i], nums[n-i-1]);
        }

        for (int i = 0; i < n; i++){
            if (nums[i] > mini[i] && nums[i] < maxi[i]) return true;
        }

        return false;
    }
};