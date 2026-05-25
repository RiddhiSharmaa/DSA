class Solution {
public:
    bool checkPalindrome(int& i, int& j, string& s){
        int left = i, right = j;
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (ans.size() < (j-i+1) && checkPalindrome(i, j, s)){
                    ans = s.substr(i, j-i+1);
                }
            }
        }

        return ans;
    }
};