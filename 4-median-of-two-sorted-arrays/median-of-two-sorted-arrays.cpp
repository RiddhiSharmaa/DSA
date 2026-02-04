class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>vec;

        for (int n : nums1){
            vec.push_back(n);
        }

        for (int n : nums2){
            vec.push_back(n);
        }

        sort(vec.begin(), vec.end());
        int total = n1+n2;

        if (total % 2 == 0){
            return (double) (vec[total/2] + vec[(total/2)-1])/2.0;
        } else {
            return (double) vec[total/2];
        }

        return -1;
    }
};