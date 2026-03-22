class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;

        while (j < nums.size()){
            if (nums[i] == nums[j]){
                j++; // points to unique number only
            } else {
                i++; // pointer to swap numbers in vector
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return i+1;
    }
};