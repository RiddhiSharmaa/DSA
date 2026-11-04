class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n-1;
        vector<int>ans;
        
        while ((right-left+1) > k){
            if (abs(arr[right]-x) >= abs(arr[left]-x)){
                right--;
            } else {
                left++;
            }
        }

        for (int i = left; i <= right; i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};