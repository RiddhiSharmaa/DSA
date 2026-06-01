class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word){
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
                if (st.find(c) != st.end()){
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (c - '0' >= 0 && c - '0' <= 9) continue;
            else return false;
        }

        if (hasVowel && hasConsonant) return true;
        return false;
    }
};