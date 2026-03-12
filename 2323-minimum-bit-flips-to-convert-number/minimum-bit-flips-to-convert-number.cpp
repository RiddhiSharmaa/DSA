class Solution {
public:
    string convert(int num){
        string n = "";
        
        while (num > 0){
            int digit = num % 2;
            n += to_string(digit);
            num /= 2;
        }
        
        reverse(n.begin(), n.end());
        return n;
    }

    int minBitFlips(int start, int goal) {
        string n1 = convert(start);
        string n2 = convert(goal);
        while (n1.size() < n2.size()) n1 = "0" + n1;
        while (n2.size() < n1.size()) n2 = "0" + n2;

        int cnt = 0;
        for (int i = 0; i < n1.size(); i++){
            if (n1[i] != n2[i]) cnt++;
        }

        return cnt;
    }
};