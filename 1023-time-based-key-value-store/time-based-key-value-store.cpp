class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>mpp;
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if (mpp.find(key) == mpp.end()){
            return "";
        } else {
            vector<pair<string, int>>& vec = mpp[key];
            int low = 0, high = vec.size()-1;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (vec[mid].second < timestamp){
                    ans = vec[mid].first;
                    low = mid + 1;
                } else if (vec[mid].second > timestamp){
                    high = mid - 1;
                } else {
                    ans = vec[mid].first;
                    return ans;
                }
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */