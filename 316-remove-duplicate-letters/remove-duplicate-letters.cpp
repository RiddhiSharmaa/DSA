class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>visited(26, 0);
        unordered_map<char, int>freq;
        string ans = "";

        for (char c : s){
            freq[c]++;
        }

        for (int i = 0; i < n; i++){
            while (!ans.empty() && s[i] <= ans.back() && freq[ans.back()] >= 1 
            && !visited[s[i]-'a']){
                visited[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            if (!visited[s[i] - 'a']) ans.push_back(s[i]);
            visited[s[i] - 'a'] = 1;
            freq[s[i]]--;
        }

        return ans;
    }
};