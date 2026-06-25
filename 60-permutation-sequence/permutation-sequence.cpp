class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>values;
        int fact = 1;
        string ans = "";

        for (int i = 1; i <= n; i++){
            values.push_back(i);
            fact *= i;
        }

        k--;

        for (int i = n; i >= 1; i--){
            fact /= i;
            int idx = k / fact;
            ans.push_back(values[idx] + '0');
            values.erase(values.begin() + idx);
            k %= fact;
        }

        return ans;
    }
};