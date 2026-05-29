class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        vector<string>ans;

        for (string i : queries){
            for (string j : dictionary){
                int cnt = 0;
                for (int k = 0; k < i.size(); k++){
                    if (i[k] != j[k])cnt++;
                    if (cnt > 2) break;
                }
                if (cnt <= 2) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};