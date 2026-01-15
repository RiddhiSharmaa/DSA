class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            unordered_set<int>st;
            for (int j = i; j < nums.size(); j++){
                st.insert(nums[j]);
                sum += nums[j];
                if (st.count(sum) > 0) cnt++;
            }
        }

        return cnt;
    }
    // int centeredSubarrays(vector<int>& nums) {
    //     int cnt = 0;
    //     int sum = 0;
    //     unordered_map<int, int>mpp;

    //     for (int i = 0; i < nums.size(); i++){
    //         int sum = nums[i];
    //         mpp[nums[i]]++;
    //         if (mpp[sum] > 0) cnt++;
    //         for (int j = i+1; j < nums.size(); j++){
    //             sum += nums[j];
    //             mpp[nums[j]]++;
    //             if (mpp[sum] > 0) cnt++;
    //         }
            
    //         for (auto& [num, freq] : mpp){
    //             freq = 0;
    //         }
    //     }

    //     return cnt;
    // }
};