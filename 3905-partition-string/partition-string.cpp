class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        unordered_set<string>st;
        vector<string>ans;
        string temp = "";

        for (int i = 0; i < n; i++){
            temp += s[i];
            while (i+1 < n && st.find(temp) != st.end()){
                i++;
                temp += s[i];
            }
            if (st.find(temp) == st.end()){
                st.insert(temp);
                ans.push_back(temp);
                temp = "";
            }
        }

        return ans;
    }
};