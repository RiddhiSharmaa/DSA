class Solution {
public:
    double helperEven(double x, long long n){
        if (n == 1) return x;
        if (x == 0) return 0;
        if (n == 0) return 1;

        double ans = 1;
        
        if (n%2 == 0){
            ans = helperEven(x, n/2);
            ans *= ans;
        } else {
            ans = helperEven(x, n-1);
            ans = x * ans;
        }

        return ans;
    }
    double myPow(double x, int n) {
        double ans = 1;
        if (n < 0) {
            long long N = -1LL * n;
            x = 1/x;
            return helperEven(x, N);
        }

        return helperEven(x, n);
    }
};