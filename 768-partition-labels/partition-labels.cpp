class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < s.size(); i++){
            mpp[s[i]-'a'] = i;
        }

        vector<int>ans;

        int end = mpp[s[0]-'a'];
        int start = 0;
        for (int i = 0; i < s.size(); i++){
            if (mpp[s[i]-'a'] > end){
                end = mpp[s[i]-'a'];
            }

            if (i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }

        return ans;
    }
};