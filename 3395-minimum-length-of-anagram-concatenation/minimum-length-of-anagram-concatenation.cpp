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

        for (int i = 0; i < divisors.size(); i++){
            bool flag = false;
            string str = s.substr(0, divisors[i]);
            sort(str.begin(), str.end());
            for (int j = divisors[i]; j < n; j += str.size()){
                string k = s.substr(j, str.size());
                sort(k.begin(), k.end());
                if (k != str){
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
            }
            if (!flag) return divisors[i];
        }

        return n;
    }
};