class Solution {
public:
    bool check(int i, int j, string& s){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if ((j-i+1) > ans.size()){
                    if (check(i, j, s)){
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return ans;
    }
};