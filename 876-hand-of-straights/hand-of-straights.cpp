class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int>mpp;

        for (int i = 0; i < n; i++){
            mpp[hand[i]]++;
        }

        int groups = n / groupSize;

        for (auto [num, freq] : mpp){
            int count = freq;
            while (count){
                if (mpp[num] == 0) continue;
                int k = num;
                for (int j = 0; j < groupSize; j++){
                    if (mpp[k] > 0){
                        mpp[k]--;
                    } else {
                        return false;
                    }
                    k++;
                }
                count--;
            }
        }

        return true;
    }
};