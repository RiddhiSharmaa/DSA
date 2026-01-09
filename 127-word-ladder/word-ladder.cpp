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
                string replacedWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++){
                    replacedWord[j] = ch;
                    
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