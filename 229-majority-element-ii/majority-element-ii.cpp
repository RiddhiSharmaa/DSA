class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++){
            if (cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2++;
            } else if (nums[i] == ele1){
                cnt1++;
            } else if (nums[i] == ele2){
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == ele1) cnt1++;
            else if (nums[i] == ele2) cnt2++;
        }

        int threshold = floor(n/3);
        if (cnt1 > threshold) ans.push_back(ele1);
        if (cnt2 > threshold) ans.push_back(ele2);
        
        return ans;
    }
};