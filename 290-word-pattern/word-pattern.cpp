class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>wordList;
        unordered_map<char, string>mpp; 
        unordered_map<string, char>mpp2;
        string word = "";

        for (int i = 0; i < s.size(); i++){
            if (!isspace(s[i])){
                word += s[i];
            } else  {
                wordList.push_back(word);
                word = "";
            }
        }
        wordList.push_back(word);

        if (pattern.size() != wordList.size()) return false;

        for (int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            if (mpp.find(ch) != mpp.end() && mpp[ch] != wordList[i]){
                return false;
            }
            mpp[ch] = wordList[i];
        }

        for (int i = 0; i < wordList.size(); i++){
            string w = wordList[i];
            if (mpp2.find(w) != mpp2.end() && mpp2[w] != pattern[i]){
                return false;
            }
            mpp2[w] = pattern[i];
        }

        return true;
    }
};