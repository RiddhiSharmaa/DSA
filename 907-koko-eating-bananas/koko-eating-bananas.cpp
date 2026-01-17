class Solution {
public:
    using ll = long long;
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = INT_MIN;
        ll ans = LLONG_MAX;

        for (int i = 0; i < piles.size(); i++){
            maxSpeed = max(maxSpeed, piles[i]);
        }

        ll low = 1, high = maxSpeed;

        while (low <= high){
            ll mid = low + (high - low)/2;
            ll hours = 0;
            for (int i = 0; i < piles.size(); i++){
                hours += ceil((double)piles[i]/(double)mid);
            }

            if (hours <= h){
                ans = mid;
                high = mid - 1;
            } else if (hours > h){
                low = mid + 1;
            }
        }
        
        return (int)ans;
    }
};