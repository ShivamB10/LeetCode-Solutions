class Solution {
public:
    struct Compare{
        bool operator()(const pair<string,int>&a,const pair<string,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>, vector<pair<string,int>>, Compare> pq; 
        unordered_map<string,int> freq;

        for(int i = 0; i< words.size(); i++){
            freq[words[i]]++;
        }

        vector<string> ans;

        for(auto it = freq.begin(); it!= freq.end(); it++){
            pq.push({it->first,it->second});
        }

        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return ans;
    }
};