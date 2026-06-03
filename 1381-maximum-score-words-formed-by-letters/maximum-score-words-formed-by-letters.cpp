class Solution {
public:
    int mpp1[26] = {0};
    int mpp2[26] = {0};
    int helper(int i, vector<string>& words){
        if (i >= words.size()) return 0;

        int s = 0;
        bool flag = true;
        for (int j = 0; j < words[i].size(); j++){
            if (mpp2[words[i][j]-'a'] > 0){
                s += mpp1[words[i][j]-'a'];
                mpp2[words[i][j]-'a']--;
            } else {
                s = 0;
                flag = false;
                int k = j-1;
                while (k >= 0){
                    mpp2[words[i][k]-'a']++;
                    k--;
                }
                break;
            }
        }

        int take = 0;
        if (flag){
            take = s + helper(i+1, words);
            for (char c : words[i]){
                mpp2[c-'a']++;
            }
        }
   
        int notTake = helper(i+1, words);

        return max(take, notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
    
        for (int i = 0; i < 26; i++){
            mpp1[i] = score[i];
        }

        for (char c : letters){
            mpp2[c-'a']++;
        }
        return helper(0, words);
    }
};