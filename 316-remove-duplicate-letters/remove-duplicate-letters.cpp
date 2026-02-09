class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int>visited(26, 0), freq(26, 0);

        for (int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }

        for (int i = 0; i < s.size(); i++){
            if (visited[s[i]-'a'] == 0){
                while (!ans.empty() && freq[ans.back()-'a'] > 0 && 
                s[i] < ans.back()){
                    visited[ans.back()-'a'] = 0;
                    ans.pop_back();
                }

                ans += s[i];
                visited[s[i]-'a'] = 1;
            } 
            freq[s[i]-'a']--;
        }

        return ans;
    }
};