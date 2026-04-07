class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>next(n, -1);
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && nums2[i] >= nums2[st.top()]){
                st.pop();
            }

            if (!st.empty()) next[i] = st.top();

            st.push(i);
        }

        vector<int>ans;
        for (int x : nums1){
            for (int i = 0; i < nums2.size(); i++){
                if (nums2[i] == x){
                    if (next[i] != -1){
                        ans.push_back(nums2[next[i]]);
                        break;
                    } else {
                        ans.push_back(-1);
                    }
                }
            }
        }

        return ans;
    }
};