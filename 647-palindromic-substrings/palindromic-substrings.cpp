class Solution {
public:
    void countPalindrome(int left, int right, int &cnt, string &s){
        while (left >= 0 && right < s.size() && left <= right && s[left] == s[right]){
            cnt++;
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++){
            int left = i, right = i;
            countPalindrome(left, right, cnt, s);

            left = i, right = i+1;
            countPalindrome(left, right, cnt, s);
        }

        return cnt;
    }

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