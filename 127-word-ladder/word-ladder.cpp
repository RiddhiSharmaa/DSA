class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        if (words.count(beginWord)) words.erase(beginWord);

        while (!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for (int j = 0; j < word.length(); j++){
                for (int i = 0; i < 26; i++){
                    string w1  = word.substr(0, j);
                    char w2 = char('a' + i);
                    string w3 = (j + 1 < word.length()) ? word.substr(1 + j, word.length() - j - 1) : "";
                    string replacedWord = w1 + w2 + w3;
                    
                    if (words.count(replacedWord)){
                        if (replacedWord == endWord){
                            return level + 1;
                        }
                        q.push({replacedWord, level+1});
                        words.erase(replacedWord);
                    }
                }
            }
        }
        
        return 0;
    }
};