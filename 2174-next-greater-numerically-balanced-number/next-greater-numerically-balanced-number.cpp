class Solution {
public:
    bool check(int i){
        int num = i;
        int freq[10] = {0};

        while (num > 0){
            int digit = num % 10;
            freq[digit] += 1;
            num /= 10;   
        }

        bool flag = true;
        for (int i = 0; i <= 9; i++){
            if (freq[i] != 0 && freq[i] != i){
                flag = false;
            }
        }

        return flag;
    }

    int nextBeautifulNumber(int n) {
        int i = n+1;
        while (i < 1e8){
            if (check(i)) return i;
            i++;
        }

        return -1;
    }
};