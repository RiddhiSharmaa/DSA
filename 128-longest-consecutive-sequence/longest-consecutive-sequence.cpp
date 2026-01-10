class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currLen = 0, ans = 0;
        unordered_set<int>st(nums.begin(), nums.end());

        for (auto num : st){
            if (st.find(num - 1) == st.end()){
                currLen = 1;

                while (st.find(num + 1) != st.end()){
                    currLen++;
                    num++;
                }
                ans = max(ans, currLen);
            }
        }

        return ans;
    }
};