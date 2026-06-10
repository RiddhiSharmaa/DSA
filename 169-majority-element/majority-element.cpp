class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1;
        int cnt = 0;

        for (int i = 0; i < n; i++){
            if (cnt == 0){
                ele1 = nums[i];
                cnt++;
            } else if (ele1 == nums[i]){
                cnt++;
            } else if (ele1 != nums[i]){
                cnt--;
            }
        }

        return ele1;
    }
};