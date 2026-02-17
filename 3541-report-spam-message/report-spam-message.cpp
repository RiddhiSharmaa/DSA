class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>ms(bannedWords.begin(), bannedWords.end());
        int cnt = 0;

        for (string msg : message){
            if (ms.find(msg) != ms.end()) cnt++;
            if (cnt >= 2) return true;
        }

        return false;
    }
};