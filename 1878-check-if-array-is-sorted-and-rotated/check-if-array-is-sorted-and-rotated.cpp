class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < 2*n; i++){
            if (cnt >= n-1) return true;
            cout << cnt << endl;
            if (i+1 < 2*n && nums[i%n] <= nums[(i+1)%n]){
                cnt++;
            }
            if (i+1 < 2*n && nums[i%n] > nums[(i+1)%n]){
                cnt = 0;
            }
        }

        return false;
    }
};