class DetectSquares {
public:
    map<pair<int, int>, int>mpp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mpp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;

        for (auto& [p, freq] : mpp){
            int x2 = p.first;
            int y2 = p.second;

            if (x1 != x2 && y1 != y2 && abs(x1-x2) == abs(y1-y2)){
                int freq1 = mpp[{x1, y2}];
                int freq2 = mpp[{x2, y1}];
                ans += freq1 * freq2 * freq;
            }
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */