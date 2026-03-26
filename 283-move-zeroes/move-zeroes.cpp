class Solution {
public:
    using ll = long long;
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPosition = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] != 0){
                swap(nums[i], nums[insertPosition]);
                insertPosition++;
            }
        }
    }
};