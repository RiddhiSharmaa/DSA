class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int>mpp;
        vector<int>ans;
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if (!st.empty()) mpp[nums2[i]] = st.top();
            else mpp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        for (int num: nums1){
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};