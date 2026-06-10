class Solution {
public:
    double helper(double x, int n){
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n == 2) return x * x;
        if (n == -1) return 1/x;

        double ans = 0.0;
        if (n % 2 == 0){
            ans = helper(x, n/2);
            ans *= ans;
        } else {
            ans = x * helper(x, n-1);
        }

        return ans;
    }
    double myPow(double x, int n) {
       
        return helper(x, n);
    }
};