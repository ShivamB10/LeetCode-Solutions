class Solution {
public:
    struct Compare{
        bool operator()(vector<int> &a, vector<int> &b){
            if(a[1] == b[1]){
                return a[2] >b[2];
            }
            else{
                return a[1] > b[1];
            }
 
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> index;
        vector<int> res;

        for(int i = 0; i < tasks.size(); i++){
            index.push_back({tasks[i][0],tasks[i][1],i});
        }

        sort(index.begin(),index.end());

        priority_queue<vector<int>,vector<vector<int>>, Compare> pq;

        long time = 0;
        int i = 0;

        while(i < tasks.size() || !pq.empty()){
            if(pq.empty() && time < index[i][0]){
                time = index[i][0];
            }

            while(i < tasks.size() && time >= index[i][0]){
                pq.push(index[i]);
                i++;
            }

            vector<int> task = pq.top();
            res.push_back(task[2]);
            pq.pop();
            time += task[1];

        }

        return res;



    }
};