class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while (!q.empty()){
            auto [word, level] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (int j = 0; j < 26; j++){
                    word[i] = char('a' + j);
                    if (st.find(word) != st.end()){
                        if (endWord == word) return level+1;
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};