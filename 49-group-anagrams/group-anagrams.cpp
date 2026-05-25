class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>ans;

        for (int i = 0; i < n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mpp[s].push_back(strs[i]);
        }

        for (auto& [s, vec] : mpp){
            ans.push_back(vec);
        }

        return ans;
    }
};