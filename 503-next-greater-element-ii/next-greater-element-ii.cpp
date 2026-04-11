class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;

        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }

        for (int i = 2*n-1; i >= 0; i--){
            while (!st.empty() && nums[i] >= st.top()){
                st.pop();
            }

            if (!st.empty()) ans[i%n] = st.top();
            st.push(nums[i]);
        }

        return ans;
    }
};