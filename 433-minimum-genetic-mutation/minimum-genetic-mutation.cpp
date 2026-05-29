class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(), bank.end());
        int cnt = 0;
        queue<pair<string, int>>q;
        q.push({startGene, 0});
        vector<char>vec = {'A', 'C', 'G', 'T'};

        while (!q.empty()){
            auto [gene, num] = q.front();
            st.erase(gene);
            q.pop();

            for (int i = 0; i < 8; i++){
                char original = gene[i];
                for (char j : vec){
                    gene[i] = j;
                    if (st.find(gene) != st.end()){
                        if (endGene == gene){
                            return num+1;
                        }
                        q.push({gene, num+1});
                    }
                }
                gene[i] = original;
            }
        }

        return -1;
    }
};