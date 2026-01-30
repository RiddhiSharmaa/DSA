class TimeMap {
public:
    map<string, vector<pair<string, int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& vec = mpp[key];
        string ans = "";
        int low = 0, high = vec.size()-1;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (vec[mid].second <= timestamp){
                ans = vec[mid].first;
                low = mid+1;
            } else {
                high = mid-1;
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