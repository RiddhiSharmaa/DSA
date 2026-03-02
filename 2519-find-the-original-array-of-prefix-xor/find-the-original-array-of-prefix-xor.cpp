class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n, 0);

        ans[0] = pref[0];
        int xorSoFar = ans[0];
        for (int i = 1; i < n; i++){
            ans[i] = xorSoFar ^ pref[i];
            xorSoFar ^= ans[i];
        }

        return ans;
    }
};