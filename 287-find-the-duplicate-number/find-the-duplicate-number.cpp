class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1, 0);

        for (int i = 0; i < n; i++){
            hash[nums[i]]++;
        }

        for (int i = 1; i <= n; i++){
            if (hash[i] > 1 ) return i;
        }

        return -1;
    }
};