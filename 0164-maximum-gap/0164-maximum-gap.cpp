class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int> pq;
        int diffMax = 0;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        int num1 = pq.top();
        pq.pop();

        while(!pq.empty()){
            diffMax = max(num1-pq.top(),diffMax);
            num1 = pq.top();
            pq.pop();
        }


        return diffMax;

        
    }
};