class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < s.size(); i++){
            mpp[s[i]-'a'] = i;
        }

        vector<int>ans;
        int i = 0;
        while (i < s.size()){
            int end = mpp[s[i]-'a'];
            int start = i;

            while (i <= end){
                end = max(end, mpp[s[i]-'a']);
                i++;
            }

            ans.push_back(end-start+1);
        }

        return ans;
    }
};