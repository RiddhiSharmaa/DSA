class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;

        for (int i = 0; i < n; i++){
            bool destroyed = true;
            
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if (abs(asteroids[i]) > st.top()){
                    st.pop();
                } else if (abs(asteroids[i]) == st.top()){
                    st.pop();
                    destroyed = false;
                    break;
                } else {
                    destroyed = false;
                    break;
                } 
            }
            
            if (destroyed) st.push(asteroids[i]);
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};