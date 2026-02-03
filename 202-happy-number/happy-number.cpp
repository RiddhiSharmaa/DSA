class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while (n > 0){
            int digit = n % 10;
            sum += (digit * digit);
            n /= 10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
        while (n != 1){
            int s = getSum(n);
            if (s == 4) return false;
            n = s;
        }

        return true;
    }
};