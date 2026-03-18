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

        while (!mpp.empty()){
            auto it = mpp.begin();
            int k = it -> first;
            for (int j = 0; j < groupSize; j++){
                if (mpp[k] > 0){
                    mpp[k]--;
                    if (mpp[k] == 0) mpp.erase(k);
                } else {
                    return false;
                }
                k++;
            }
        }

        return true;
    }
};