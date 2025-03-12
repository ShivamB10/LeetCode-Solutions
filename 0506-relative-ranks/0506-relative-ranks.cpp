class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int>&a, const pair<int,int> &b){
            return a.first < b.first;
        }
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> index;
        int n = score.size();
        vector<string> result(n);
        priority_queue <pair<int,int>,vector<pair<int,int>>,Compare> pq; 

        for(int i = 0; i < n; i++){
            index[score[i]] = i;
        }

        for(auto it = index.begin(); it != index.end(); it++){
            pq.push({it->first,it->second});
        }

        int rank = 1;
        while(!pq.empty()){
            if(rank == 1){
                result[pq.top().second] = "Gold Medal"; 
            }
            else if(rank == 2){
                result[pq.top().second] = "Silver Medal";
            }
            else if(rank == 3){
                result[pq.top().second] = "Bronze Medal";
            }
            else{
                string val = to_string(rank);
                result[pq.top().second] = val;
            }

            pq.pop();
            rank++;
        }

        return result;
    }
};