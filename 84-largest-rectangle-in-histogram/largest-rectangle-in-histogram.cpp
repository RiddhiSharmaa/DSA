class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n, n);
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        vector<int>pse(n, -1);
        stack<int>st2;

        for (int i = 0; i < n; i++){
            while (!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if (!st2.empty()) pse[i] = st2.top();
            st2.push(i);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++){
            int area = ((nse[i]-1) - (pse[i]+1) + 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};