class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        int left = i, right = j;

        while (left < right){
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        int left = 0, right = n-1;
        int startIdx, endIdx;

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (isPalindrome(i,j, s) && (j-i+1) > ans.length()){
                    ans = s.substr(i, j-i+1);
                }
            }
        }

        return ans;
    }
};