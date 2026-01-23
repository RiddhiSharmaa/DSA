class Solution {
public:
    bool checkPalindrome(int i, int j, string &s, vector<vector<int>>& dp){
        if (i > j) {
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]){
            return dp[i][j] = checkPalindrome(i+1, j-1, s, dp);
        }

        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<vector<int>>dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (checkPalindrome(i, j, s, dp)) cnt++;
            }
        }

        return cnt;
    }
    // void countPalindrome(int left, int right, int &cnt, string &s){
    //     while (left >= 0 && right < s.size() && left <= right && s[left] == s[right]){
    //         cnt++;
    //         left--;
    //         right++;
    //     }
    // }

    // int countSubstrings(string s) {
    //     int n = s.size();
    //     int cnt = 0;

    //     for (int i = 0; i < n; i++){
    //         int left = i, right = i;
    //         countPalindrome(left, right, cnt, s);

    //         left = i, right = i+1;
    //         countPalindrome(left, right, cnt, s);
    //     }

    //     return cnt;
    // }

    // bool isPalindrome(int i, int j, string& s){
    //     int left = i, right = j;

    //     while (left < right){
    //         if (s[left] != s[right]){
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }

    //     return true;
    // }
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     int cnt = 0;

    //     for (int i = 0; i < n; i++){
    //         for (int j = i; j < n; j++){
    //             if (s[i] == s[j] && isPalindrome(i, j, s)){
    //                 cnt++;
    //             }
    //         }
    //     }

    //     return cnt;
    // }
};