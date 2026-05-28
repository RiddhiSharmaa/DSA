class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while (!q.empty()){
            auto [word, level] = q.front();
            st.erase(word);
            q.pop();

            for (int i = 0; i < word.size(); i++){
                for (int j = 0; j < 26; j++){
                    string w1 = word.substr(0, i);
                    char w2 = char('a' + j);
                    string w3 = word.substr(i+1);
                    string w = w1 + w2 + w3;

                    if (st.find(w) != st.end()){
                        if (endWord == w) return level+1;
                        q.push({w, level+1});
                        st.erase(w);
                    }
                }
            }
        }

        return 0;
    }
};