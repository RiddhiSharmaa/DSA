class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>ans(tasks.size(), 0);
        priority_queue<pair<int, int>>pq;
        unordered_map<char, int>mpp;

        for (int i = 0; i < tasks.size(); i++){
            mpp[tasks[i]]++;
        }

        for (auto& [ch, freq] : mpp) pq.push({freq, ch - 'A'});
        
        int cycle = tasks.size();
        int time = 0;

        while (cycle && !pq.empty()){
            int c = n+1;
            vector<pair<int, int>>remain;
            while (c){
                int topfreq = 0, topchar = 0;
                if (!pq.empty()) topfreq = pq.top().first;
                if (!pq.empty()) topchar = pq.top().second;
                pq.pop();
                topfreq--;
                if (topfreq > 0){
                    remain.push_back({topfreq, topchar});
                }
                c--;
                time++;
                if (pq.empty()) break;
            }
            
            if (c != 0 && remain.size() > 0) time += c;
            if (remain.size() > 0){
                for (auto& p : remain){
                    pq.push(p);
                }
            }

            cycle--;
        }

        return time;
    }
};