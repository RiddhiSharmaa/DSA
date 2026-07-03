class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int ans = -1;
        if (m == 0) return -1;
        if (m > n) return -1;

        for (int i = 0; i < n; i++){
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};