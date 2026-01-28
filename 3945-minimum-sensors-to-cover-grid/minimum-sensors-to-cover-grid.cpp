class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = (2*k) + 1;
        int rowSensors = ceil(n/(float)side);
        int colSensors = ceil(m/(float)side);

        return rowSensors * colSensors;
    }
};