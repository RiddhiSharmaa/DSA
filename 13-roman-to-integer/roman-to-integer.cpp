class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500},{'M', 1000}};

        for (int i = 0; i < n; i++){
            if (s[i] == 'I') {
                if (i+1 < n && s[i+1] == 'V'){
                    ans += 4;
                    i++;
                } else if (i+1 < n && s[i+1] == 'X'){
                    ans += 9;
                    i++;
                } else {
                    ans += 1;
                }
            } else if (s[i] == 'X') {
                if (i+1 < n && s[i+1] == 'L'){
                    ans += 40;
                    i++;
                } else if (s[i+1] == 'C'){
                    ans += 90;
                    i++;
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'C') {
                if (i+1 < n && s[i+1] == 'D'){
                    ans += 400;
                    i++;
                } else if (s[i+1] == 'M'){
                    ans += 900;
                    i++;
                } else {
                    ans += 100;
                }
            } else if (mpp.find(s[i]) != mpp.end()){
                ans += mpp[s[i]];
            }
        }

        return ans;
    }
};