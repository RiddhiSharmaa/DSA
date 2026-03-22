class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int>mpp;

        for (int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        int i = 0;
        for (auto& [num, freq]: mpp){
            nums[i] = num;
            i++;
        }

        sort(nums.begin(), nums.begin()+mpp.size());
        return mpp.size();
    }
};