class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            if(pq.size()<k){
                pq.push({nums[i],i});
            }

            else if(pq.size() == k){
                if(pq.top().first < nums[i]){
                    pq.pop();
                    pq.push({nums[i],i});
                }
            }
        }


        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        for(int j = 0; j < ans.size(); j++){
            int element = nums[ans[j]];
            ans[j] = element;
        }


        return ans;

    }
};