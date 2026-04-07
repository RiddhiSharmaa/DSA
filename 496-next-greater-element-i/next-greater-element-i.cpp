class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>next(n, -1);
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if (!st.empty()) next[i] = st.top();

            st.push(nums2[i]);
        }

        vector<int>ans;
        for (int x : nums1){
            for (int i = 0; i < nums2.size(); i++){
                if (nums2[i] == x){
                    ans.push_back(next[i]);
                }
            }
        }

        return ans;
    }
};