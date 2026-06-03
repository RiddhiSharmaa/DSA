class Solution {
public:
    int helper(int i, vector<string>& words, unordered_map<char, int>& mpp1,
    unordered_map<char, int>& mpp2){
        if (i >= words.size()) return 0;

        int s = 0;
        bool flag = true;
        for (int j = 0; j < words[i].size(); j++){
            if (mpp2[words[i][j]] > 0){
                s += mpp1[words[i][j]];
                mpp2[words[i][j]]--;
            } else {
                s = 0;
                flag = false;
                int k = j-1;
                while (k >= 0){
                    mpp2[words[i][k]]++;
                    k--;
                }
                break;
            }
        }

        int take = 0;
        if (flag){
            take = s + helper(i+1, words, mpp1, mpp2);
            for (char c : words[i]){
                mpp2[c]++;
            }
        }
   
        int notTake = helper(i+1, words, mpp1, mpp2);

        return max(take, notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        unordered_map<char, int>mpp1, mpp2;

        for (int i = 0; i < 26; i++){
            mpp1[i+'a'] = score[i];
        }

        for (char c : letters){
            mpp2[c]++;
        }

        // vector<vector<int>>dp(n+1, vector<int>())
        return helper(0, words, mpp1, mpp2);
    }
};