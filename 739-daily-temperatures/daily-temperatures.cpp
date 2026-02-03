class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n, 0);
        unordered_map<int, int>mpp;
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }

            if (!st.empty()) mpp[i] = st.top();
            else mpp[i] = -1;

            st.push(i);
        }

        for (auto [i, end] : mpp){
            if (end != -1){
                ans[i] = end - i;
            }
        }

        return ans;
    }
};