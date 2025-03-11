class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        }
    };
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size();i++){
            freq[arr[i]]++;
        }

        int n = arr.size();
        int count = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> pq;

        for(auto it = freq.begin(); it!= freq.end(); it++){
            pq.push({it->first,it->second});
        }

        while(n > arr.size()/2){
            n = n - (pq.top().second);
            pq.pop();
            count++;
        }

        return count;
    }
};