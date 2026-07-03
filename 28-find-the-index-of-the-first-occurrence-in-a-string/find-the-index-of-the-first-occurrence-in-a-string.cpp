class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int ans = -1;
        int i = 0;

        while (i < n){
            if (haystack.substr(i, m) == needle) {
                return i;
            }
            i++;
        }

        return -1;
    }
};