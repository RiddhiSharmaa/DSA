class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>st;

        for (int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int i = 0;
        for (auto& it : st){
            nums[i] = it;
            i++;
        }

        sort(nums.begin(), nums.begin()+st.size());
        return st.size();
    }
};