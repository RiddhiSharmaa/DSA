class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        // sort(hand.begin(), hand.end());

        // for (int i = 0; i < n; i += groupSize){
        //     for (int j = i; j < i + groupSize - 1; j++){
        //         if (hand[j+1] == hand[j] || hand[j+1] > hand[j] + 1) return false;
        //     }
        // }

        multiset<int>ms(hand.begin(), hand.end());

        int groups = n / groupSize;

        for (int i = 0; i < groups; i++){
            auto it = ms.begin();
            int num = *it;
            ms.erase(it);
            for (int j = 0; j < groupSize-1; j++){
                auto it2 = ms.find(num+1);
                if (it2 != ms.end()){
                    ms.erase(it2);
                } else {
                    return false;
                }
                num++;
            }
        }

        return true;
    }
};