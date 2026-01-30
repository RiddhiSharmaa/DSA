class TimeMap {
public:
    map<string, vector<pair<string, int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mpp.find(key) == mpp .end()) return "";
        int t = INT_MAX;
        for (auto it = mpp.rbegin(); it != mpp.rend(); ++it){
            string k = it->first;
            vector<pair<string, int>>& vec = it->second;
            if (k == key){
                for (int i = vec.size()-1; i >= 0; i--){
                    auto p = vec[i];
                    if (p.second <= timestamp){
                        return p.first;
                    }
                }
            }
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */