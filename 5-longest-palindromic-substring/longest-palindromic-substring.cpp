class Solution {
public:
    string longestPalindrome(string s) {
        int start = INT_MIN, end = INT_MIN;
        string ans = "";

        for (int i = 0; i < s.size(); i++){
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]){
                if (right-left+1 > ans.size()){
                    // start = left;
                    // end = right;
                    ans = s.substr(left, right-left+1);
                }
                left--;
                right++;
            }

            left = i, right = i+1;
            while (left >= 0 && right < s.size() && s[left] == s[right]){
                if (right-left+1 > ans.size()){
                    // start = left;
                    // end = right;
                    ans = s.substr(left, right-left+1);
                }
                left--;
                right++;
            }
        }

        return ans;
    }
    // bool isPalindrome(int i, int j, string& s){
    //     int left = i, right = j;

    //     while (left <= right){
    //         if (s[left] != s[right]){
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }

    //     return true;
    // }

    // string longestPalindrome(string s) {
    //     string ans = "";
    //     int n = s.size();
    //     int left = 0, right = n-1;
    //     int startIdx, endIdx;

    //     for (int i = 0; i < n; i++){
    //         for (int j = i; j < n; j++){
    //             if (isPalindrome(i,j, s) && (j-i+1) > ans.length()){
    //                 ans = s.substr(i, j-i+1);
    //             }
    //         }
    //     }

    //     return ans;
    // }
};