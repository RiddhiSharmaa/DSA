class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int cnt = 0;

        for (int j = 0; j < m; j++){
            int num = nums2[j] * k;
            for (int i = 0; i < n; i++){
                if (nums1[i] % num == 0) cnt++;
            }
        }

        return cnt;
    }
};