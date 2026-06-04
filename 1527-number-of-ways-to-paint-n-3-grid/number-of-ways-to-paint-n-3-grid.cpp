class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1000000007;
        long long x = 6, y = 6;
        
        for (int i = 2; i <= n; i++){
            int waysX = (3*x + 2*y) % MOD;
            int waysY = (2*x + 2*y) % MOD;
            x = waysX;
            y = waysY;
        }

        return (x+y) % MOD;
    }
};