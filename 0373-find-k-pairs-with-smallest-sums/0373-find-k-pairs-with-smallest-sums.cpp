class Solution {
public:
    struct Compare{
        bool operator()(const pair<vector<int>, int>& a, const pair<vector<int>, int>& b){
            return (a.first[0]+a.first[1]) > (b.first[0]+b.first[1]);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, Compare>pq;
      vector<vector<int>> ans;
      for(int i = 0; i < min(int(nums1.size()), k); i++){
            pq.push({{nums1[i], nums2[0]},0});
        }
      

      while(k-- && !pq.empty()) {
        int pos = pq.top().second;
        vector<int> pair = pq.top().first;
        ans.push_back(pair);
        pq.pop();

        if(pos+1 < nums2.size()){
            pq.push({{pair[0], nums2[pos+1]},pos+1});
        }
      }

      return ans;  
    }
};