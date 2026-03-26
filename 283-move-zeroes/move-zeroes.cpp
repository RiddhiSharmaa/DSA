class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = n-1, right = n-1;
        vector<int>vec;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0){
                vec.push_back(nums[i]);
            }
        }

        for (int i = 0; i < n; i++){
            if (i < vec.size()){
                nums[i] = vec[i];
            } else {
                nums[i] = 0;
            }
        }

        // bool s = false;

        // for (int i = 0; i < n; i++){
        //     if (nums[i] == 0) s = true;
        //     else continue;
        //     int prev = i;

        //     for (int j = i+1;  j < n; j++){
        //         if (nums[j] == 0) continue;
        //         if (s){
        //             swap(nums[j], nums[prev]);
        //         }
        //         prev = j-1;
        //     }
        //     s = false;
        // }
    }
};