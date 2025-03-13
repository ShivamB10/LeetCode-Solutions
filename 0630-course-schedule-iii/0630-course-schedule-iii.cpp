class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            return a.second > b.second;
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        priority_queue<int> max_pq;

        for(int i = 0; i < courses.size(); i++){
            pq.push({courses[i][0],courses[i][1]});
        }

        int curr_days = 0;
        

        while(!pq.empty()){
            if(curr_days + pq.top().first <= pq.top().second){
                curr_days += pq.top().first;
                max_pq.push(pq.top().first);
            }

            else if(!max_pq.empty() && max_pq.top() > pq.top().first){
                curr_days -= max_pq.top();
                max_pq.pop();
                curr_days += pq.top().first;
                max_pq.push(pq.top().first);
            }

            pq.pop();


        }

        return max_pq.size();
    }
};