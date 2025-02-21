class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        vector <int> result;

        for(int i = 0; i< nums.size(); i++){
            count[nums[i]] += 1;
        }

        priority_queue <pair<int,int>> count_queue;

        for(auto it = count.begin(); it!= count.end(); it++){
            count_queue.push({it->second, it->first});
        }

        while(k>0){
            auto [count, element] = count_queue.top();
            result.push_back(element);
            count_queue.pop();
            k--;
        }

        return result;
    }
};