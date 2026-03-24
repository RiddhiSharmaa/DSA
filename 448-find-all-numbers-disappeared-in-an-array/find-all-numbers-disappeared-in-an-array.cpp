class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_set<int>s1;

        for (int i = 0; i < n; i++) {
            s1.insert(nums[i]);
        }

        for (int i = 1; i <= n; i++){
            if (s1.find(i) == s1.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};