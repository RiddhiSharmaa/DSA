class Solution {
public:
    int getNextNum(int n){
        int sum = 0;
        while (n > 0){
            int digit = n % 10;
            sum += (digit * digit);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;

        while (st.find(n) == st.end()){
            st.insert(n);
            if (n == 1) return true;
            n = getNextNum(n);
        }

        return false;
    }
};