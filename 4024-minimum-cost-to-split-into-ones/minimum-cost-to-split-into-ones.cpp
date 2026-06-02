class Solution {
public:
    int minCost(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        int cost = 0;
        if (n % 2 != 0){
            cost = n-1 + minCost(n-1);
        } else {
            cost = n/2 * n/2 + 2 * minCost(n/2);
        }

        return cost;
    }
};