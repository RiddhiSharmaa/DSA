class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;

        for (int i = 0; i < n; i++){
            while (ans.size() >= 2 && ans.back() < 0 && ans[ans.size()-2] > 0){
                if (abs(ans.back()) > ans[ans.size()-2]){
                    ans[ans.size()-2] = ans.back();
                } else if (abs(ans.back()) == ans[ans.size()-2]){
                    ans.pop_back();
                }
                ans.pop_back();
            }

            ans.push_back(asteroids[i]);
        }

        while (ans.size() >= 2 && ans.back() <= 0 && ans[ans.size()-2] > 0){
            if (abs(ans.back()) > ans[ans.size()-2]){
                ans[ans.size()-2] = ans.back();
            } else if (abs(ans.back()) == ans[ans.size()-2]){
                ans.pop_back();
            }
            ans.pop_back();
        }

        return ans;
    }
};