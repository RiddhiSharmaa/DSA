class Solution {
public:
    bool check(string s){
        for (int i = 0; i < s.size()/2; i++){
            if (s[i] != s[s.size()-i-1]) return false;
        }

        return true;
    }
    int longestPalindrome(string s, string t) {
        int cnt =1 ;
        if (check(s)) {
            int len = s.size();
            cnt = max(cnt, len);
        }
        if (check(t)) {
            int len = t.size();
            cnt = max(cnt, len);
        }

        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++){
                string a = s.substr(i, j-i+1);
                if (check(a)) {
                    int siz = a.size();
                    cnt = max(cnt, siz);
                }
            }
        }

        for (int k = 0; k < t.size(); k++){
            for (int l = k; l < t.size(); l++){
                string b = t.substr(k, l-k+1);
                if (check(b)) {
                    int siz = b.size();
                    cnt = max(cnt, siz);
                }
            }
        }
            
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++){
                string a = s.substr(i, j-i+1);
                for (int k = 0; k < t.size(); k++){
                    for (int l = k; l < t.size(); l++){
                        string b = t.substr(k, l-k+1);
                        if (check(a+b)) {
                            int siz = a.size()+b.size();
                            cnt = max(cnt, siz);
                        }
                    }
                }
            }
        }

        return cnt;
    }
};