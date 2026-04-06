class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int n = capacity.size();
        int mini = INT_MAX;

        for (int i = n-1; i >= 0; i--){
            if (capacity[i] >= itemSize){
                if (mini >= capacity[i]-itemSize){
                    mini = capacity[i]-itemSize;
                    ans = i;
                }
            }
        }

        return ans;
    }
};