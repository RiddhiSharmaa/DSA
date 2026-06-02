class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int>divisors;

        int i = 1;
       for (int i = 1; i*i <= n; i++){
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n/i) {
                    divisors.push_back(n/i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());

        bool flag = false;
        for (int i : divisors){
            vector<int>v(26, 0);
            for (int j = 0; j < i; j++){
                v[s[j] - 'a']++;
            }

            for (int j = i; j < n; j += i){
                vector<int>t(26, 0);
                for (int k = j; k < i+j; k++){
                    t[s[k] - 'a']++;
                }
                if (t != v){
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
            }

            if (!flag) return i;
        }

        return n;
    }
};