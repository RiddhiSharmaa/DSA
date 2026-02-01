class Solution {
public:
    string reverseByType(string s){
        int i = 0, j = s.size()-1;

        while (i <= j){
            if (isalpha(s[i]) && isalpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (!isalpha(s[i])) {
                i++;
            } else if (!isalpha(s[j])) {
                j--;
            }
        }

        i = 0, j = s.size()-1;
        while (i <= j){
            if (!isalpha(s[i]) && !isalpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isalpha(s[i])) {
                i++;
            } else if (isalpha(s[j])) {
                j--;
            }
        }

        return s;
    }
    // string reverseByType(string s) {
    //     string low = "";
    //     string other = "";
        

    //     for (int i = 0; i < s.size(); i++){
    //         if (isalpha(s[i])){
    //             low += s[i];
    //         } else {
    //             other += s[i];
    //         }
    //     }

    //     reverse(low.begin(), low.end());
    //     reverse(other.begin(), other.end());

    //     string ans = "";
    //     int k = 0, j = 0;
    //     for (int i = 0; i < s.size(); i++){
    //         if (isalpha(s[i])){
    //             ans += low[k];
    //             k++;
    //         } else {
    //             ans += other[j];
    //             j++;
    //         }
    //     }

    //     return ans;
    // }
};