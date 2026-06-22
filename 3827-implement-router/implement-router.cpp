class Router {
public:
    map<vector<int>, int>mpp;
    queue<vector<int>>q;
    unordered_map<int, vector<int>>timestamps;
    unordered_map<int, int>removed;
    int maxSize = 0;

    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>packet = {source, destination, timestamp};
        if (mpp[packet] != 0) return false;
        if (q.size() == maxSize){
            vector<int>toRemove = q.front();
            mpp.erase(toRemove);
            removed[toRemove[1]]++;
            q.pop();
        } 
        q.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        vector<int>res = q.front();
        mpp.erase(res);
        removed[res[1]]++;
        q.pop();
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (timestamps.find(destination) == timestamps.end()) return 0;
        auto& p = timestamps[destination];
        int temp = removed[destination];
        auto right = lower_bound(p.begin()+temp, p.end(), startTime);
        auto left = upper_bound(p.begin()+temp, p.end(), endTime);
        return int(left-right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */