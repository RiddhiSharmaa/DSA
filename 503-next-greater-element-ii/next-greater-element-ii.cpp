class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        vector<int>v = nums;
        stack<int>st;

        for (int i = 0; i < n; i++){
            v.push_back(nums[i]);
        }

        for (int i = 2*n-1; i >= 0; i--){
            while (!st.empty() && v[i] >= st.top()){
                st.pop();
            }

            if (!st.empty()) ans[i%n] = st.top();
            st.push(v[i]);
        }

        return ans;
    }
};