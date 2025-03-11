class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        priority_queue<int> pq;

        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]]++;
        }

        for(auto it= freq.begin(); it!=freq.end(); it++){
            pq.push(it->second);
        }

        int time = 0;

        while(!pq.empty()){

            vector<int>remain_tasks;
            int cycle = n+1;

            while(!pq.empty() && cycle >0){
                int max_freq = pq.top();
                pq.pop();
                if(max_freq > 1){
                    remain_tasks.push_back(max_freq-1);
                }
                time++;
                cycle--;
            }

            for(int j = 0; j < remain_tasks.size(); j++){
                pq.push(remain_tasks[j]);
            }

            if(pq.empty()){
                break;
            }

            time += cycle;

        }

        return time;
    }
};