class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>vec;

        for (int i = 0; i <= n; i++){
            int ans = 0;
            int num = i;
            string s = "";
            while (num > 0){
                int digit = num % 2;
                s += digit + '0';
                num /= 2;
            }

            for (char c : s){
                if (c == '1') ans++;
            }

            vec.push_back(ans);
        }

        return vec;
    }
};