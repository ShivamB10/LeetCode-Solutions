class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for(int i = 0; i < difficulty.size(); i++){
            jobs.push_back({difficulty[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int profits = 0;
        int curr_profit = 0;
        int j = 0;

        for(int i = 0; i < worker.size();i++){
            
            while(j < jobs.size() && worker[i] >= jobs[j].first){
                curr_profit = max(curr_profit, jobs[j].second);
                j++;
            }

            profits+= curr_profit;

        }

        return profits;
    }
};