class Solution {
public:
    int start = 0, end = 0, maxLen = INT_MIN;
    bool isPalindrome(int i, int j, vector<vector<int>>& dp, string &s){
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j] && isPalindrome(i+1, j-1, dp, s)){
            if ((j-i+1) > (end-start+1)){
                start = i;
                end = j;
            }

            return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s){
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                isPalindrome(i, j, dp, s);
            }
        }

        string ans = s.substr(start, end-start+1);
        return ans;
    }

    // O(n^2)
    // string longestPalindrome(string s) {
    //     int start = 0, end = 0;

    //     for (int i = 0; i < s.size(); i++){
    //         int left = i, right = i;
    //         while (left >= 0 && right < s.size() && s[left] == s[right]){
    //             if (right-left+1 > end-start+1){
    //                 start = left;
    //                 end = right;
    //             }
    //             left--;
    //             right++;
    //         }

    //         left = i, right = i+1;
    //         while (left >= 0 && right < s.size() && s[left] == s[right]){
    //             if (right-left+1 > end-start+1){
    //                 start = left;
    //                 end = right;
    //             }
    //             left--;
    //             right++;
    //         }
    //     }

    //     string ans = s.substr(start, end-start+1);
    //     return ans;
    // }

    // O(n^3)
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