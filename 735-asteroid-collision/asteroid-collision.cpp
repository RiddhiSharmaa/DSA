class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;

        for (int i = 0; i < n; i++){
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0 && 
            abs(asteroids[i]) > st.top()){
                st.pop();
            }
            if (!st.empty() && st.top() > 0 && asteroids[i] < 0 && 
            abs(asteroids[i]) == st.top()){
                st.pop();
                continue;
            }

            if (!st.empty() && st.top() > 0 && asteroids[i] < 0 && 
            abs(asteroids[i]) < st.top()) continue;

            st.push(asteroids[i]);
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};