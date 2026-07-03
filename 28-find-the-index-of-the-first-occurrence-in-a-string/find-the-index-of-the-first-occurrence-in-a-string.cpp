class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int ans = -1;
        int i = 0;

        for (int i = 0; i < n; i++){
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};