class StockSpanner {
public:
    unordered_map<int, int>mpp;
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (mpp.size() == 0){
            mpp[price] = 1;
            v.push_back(price);
            return 1;
        }
        int i = v.size()-1;
        int cnt = 1;
        while (i >= 0 && v[i] <= price){
            cnt++;
            i--;
        }
        mpp[price] = cnt;
        v.push_back(price);
        return mpp[price];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */