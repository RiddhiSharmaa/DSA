class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1, cnt = 0;

        for (int i = 0; i < n; i++){
            if (cnt == 0){
                ele1 = nums[i];
                cnt++;
            } else if (cnt > 0 && nums[i] == ele1){
                cnt++;
            } else {
                cnt--;
            }
        }

        return ele1;
    }
};