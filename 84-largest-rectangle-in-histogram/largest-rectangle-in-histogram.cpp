class Solution {
public:
    void helperPSE(vector<int>& heights, vector<int>& pse){
            int n = heights.size();
            stack<int>st;

            for (int i = 0; i < n; i++){
                while (!st.empty() && heights[i] <= heights[st.top()]){
                    st.pop();
                }
                if (!st.empty()) pse[i] = st.top();
                st.push(i);
            }

            return;
        }

    void helperNSE(vector<int>& heights, vector<int>& nse){
        int n = heights.size();
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        return;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n, n), pse(n, -1);
        helperNSE(heights, nse);
        helperPSE(heights, pse);
        int ans = 0;

        for (int i = 0; i < n; i++){
            ans = max(ans, (nse[i] - pse[i] - 1) * heights[i]);
        }

        return ans;
    }
};