class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>combined;
        for (int i = 0; i < nums1.size(); i++){
            combined.push_back(nums1[i]);
        }

        for (int j = 0; j < nums2.size(); j++){
            combined.push_back(nums2[j]);
        }

        sort(combined.begin(), combined.end());

        int n = combined.size();
        double ans = 0;

        if (n % 2 == 0){
            ans = (combined[(n/2.0) -1] + combined[n/2.0])/2.0;
        } else {
            ans = combined[n/2];
        }

        return ans;
    }
};