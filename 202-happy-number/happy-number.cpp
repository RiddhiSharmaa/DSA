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
        int slow = getNextNum(n);
        int fast = getNextNum(getNextNum(n));

        while (slow != fast){
            if (fast == 1) return true;
            slow = getNextNum(slow);
            fast = getNextNum(getNextNum(fast));
        }

        return (slow == 1);
    }
};