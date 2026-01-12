class Solution {
public:
    void dfs(string node, vector<string>& itinerary, 
    unordered_map<string, deque<string>>& mpp){

        while (!mpp[node].empty()){
            string next = mpp[node].front();
            mpp[node].pop_front();
            dfs(next, itinerary, mpp);
        }

        itinerary.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>>mpp;
        sort(tickets.begin(), tickets.end());

        for (auto& ticket : tickets){
            mpp[ticket[0]].push_back(ticket[1]);
        }

        vector<string> itinerary;

        dfs("JFK", itinerary, mpp);
        
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};