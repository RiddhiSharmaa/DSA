class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int cnt = 0, total = n1+n2, i = 0, j = 0;
        int ele1 = -1, ele2 = -1;

        while (i < n1 && j < n2){
            if (nums1[i] <= nums2[j]){
                if (cnt == (total/2)-1){
                    ele1 = nums1[i];
                } else if (cnt == total/2){
                    ele2 = nums1[i];
                }
                i++;
                cnt++;
            } else if (nums1[i] > nums2[j]){
                if (cnt == (total/2)-1){
                    ele1 = nums2[j];
                } else if (cnt == total/2){
                    ele2 = nums2[j];
                }
                j++;
                cnt++;
            } 
        }
        
        while (i < n1){
            if (cnt == (total/2)-1){
                ele1 = nums1[i];
            } else if (cnt == total/2){
                ele2 = nums1[i];
            }
            i++;
            cnt++;
        }

        while (j < n2){
            if (cnt == (total/2)-1){
                ele1 = nums2[j];
            } else if (cnt == total/2){
                ele2 = nums2[j];
            }
            j++;
            cnt++;
        }

        if (total % 2 == 0){
            return (double) (ele1 + ele2)/2.0;
        } else {
            return (double) ele2;
        }

        return -1;
    }
};