class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>visited(26, 0);
        unordered_map<char, int>freq;
        stack<char>st;
        string ans = "";

        for (char c : s){
            freq[c]++;
        }

        for (int i = 0; i < n; i++){
            while (!st.empty() && s[i] <= st.top() && freq[st.top()] >= 1 
            && !visited[s[i]-'a']){
                visited[st.top() - 'a'] = 0;
                st.pop();
            }

            if (!visited[s[i] - 'a']) st.push(s[i]);
            visited[s[i] - 'a'] = 1;
            freq[s[i]]--;
        }

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};