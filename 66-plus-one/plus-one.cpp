class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] < 9){
            digits[n-1]++;
            return digits;
        } else {
            int i = 0;
            reverse(digits.begin(), digits.end());
            int remaining = 0;
            while (i < n && digits[i] == 9){
                int num = digits[i];
                num++;
                digits[i] = num%10;
                remaining = num/10;
                i++;
            }

            if (remaining > 0 && i < n){
                digits[i] += remaining;
            }

            if (remaining > 0 && i >= n){
                digits.push_back(remaining);
            }
            reverse(digits.begin(), digits.end());
        }

        return digits;
    }
};