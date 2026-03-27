class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int>mpp;

        for (int i = 0; i < arr.size(); i++){
            mpp[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); i++){
            int num = 2 * arr[i];
            if (mpp.find(num) != mpp.end() && mpp[num] != i) return true;
        }

        return false;
    }
};