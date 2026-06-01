class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string, int>mpp;

        int i = 0;
        while (i < n){
            mpp[word.substr(i, k)]++;
            i += k;
        }
        
        int freq = INT_MIN;
        for (auto& [s, f] : mpp){
            if (f > freq){
                freq = f;
            }
        }

        return (n/k) - freq;
    }
};