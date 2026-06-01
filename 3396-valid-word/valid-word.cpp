class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word){
            if (!isalnum(c)) return false;
            if (isalpha(c)){
                if (st.find(c) != st.end()){
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        if (hasVowel && hasConsonant) return true;
        return false;
    }
};