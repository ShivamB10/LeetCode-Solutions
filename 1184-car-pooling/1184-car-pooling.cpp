class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            if(a.first == b.first){
                return a.second >b.second;
            }
            
            return a.first > b.first;
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

        for(int i = 0; i < trips.size(); i++){
            pq.push({trips[i][1], trips[i][0]});
            pq.push({trips[i][2],trips[i][0]*(-1)});
        }

        int current_cap = 0;

        while(!pq.empty()){
            current_cap += pq.top().second;
            pq.pop();

            if (current_cap > capacity){
                return false;
            }
        }

        return true;

    }
};