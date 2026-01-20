class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ele1 = -1, ele2 = -1, n1 = nums1.size(), n2 = nums2.size();
        int cnt = 0, i = 0, j = 0;
        int n = n1 + n2;

        while (i < n1 && j < n2){
            if (nums1[i] < nums2[j]){
                if (cnt == n/2){
                    ele2 = nums1[i];
                } else if (cnt == (n/2) - 1){
                    ele1 = nums1[i];
                }

                i++;
                cnt++;
            } else {
                if (cnt == n/2){
                    ele2 = nums2[j];
                } else if (cnt == (n/2) - 1){
                    ele1 = nums2[j];
                }

                j++;
                cnt++;
            }
        }

        while (i < n1){
            if (cnt == n/2){
                ele2 = nums1[i];
            } else if (cnt == (n/2) - 1){
                ele1 = nums1[i];
            }

            i++;
            cnt++;
        }

        while (j < n2){
            if (cnt == (n/2)){
                ele2 = nums2[j];
            } else if (cnt == (n/2) - 1){
                ele1 = nums2[j];
            }

            j++;
            cnt++;
        }

        double ans = 0;
        if (n % 2 == 0){
            ans = (double)(ele1 + ele2) / 2.0;
        } else {
            ans = (double)ele2;
        }

        return ans;
    }

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>combined;
    //     for (int i = 0; i < nums1.size(); i++){
    //         combined.push_back(nums1[i]);
    //     }

    //     for (int j = 0; j < nums2.size(); j++){
    //         combined.push_back(nums2[j]);
    //     }

    //     sort(combined.begin(), combined.end());

    //     int n = combined.size();
    //     double ans = 0;

    //     if (n % 2 == 0){
    //         ans = (combined[(n/2.0) -1] + combined[n/2.0])/2.0;
    //     } else {
    //         ans = combined[n/2];
    //     }

    //     return ans;
    // }
};