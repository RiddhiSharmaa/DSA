class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int startIdx = 0;
        int totalGas = 0, totalCost = 0, currGas = 0;

        for (int i = 0; i < n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalCost > totalGas) return -1;

        for (int i = 0; i < n; i++){
            currGas += gas[i] - cost[i];

            if (currGas < 0){
                startIdx = i+1;
                currGas = 0;
            }
        }

        return startIdx;
    }
};