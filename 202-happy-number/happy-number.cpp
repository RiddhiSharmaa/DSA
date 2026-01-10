class Solution {
public:
    int getNextNumber(int n){
        int sum = 0;
        while (n != 0){
            int num = n % 10;
            sum += (num * num);
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;

        while (n != 1 && st.count(n) == 0){
            st.insert(n);
            n = getNextNumber(n);
        }

        if (n == 1) return true;
        return false;
    }
};