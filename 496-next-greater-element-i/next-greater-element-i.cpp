class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(), -1);

        for (int i = 0; i < nums1.size(); i++){
            int num = nums1[i];
            for (int k = 0; k < nums2.size(); k++){
                if (nums2[k] == num){
                    for (int j = k+1; j < nums2.size(); j++){
                        if (nums2[j] > nums2[k]){
                            ans[i] = nums2[j];
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};