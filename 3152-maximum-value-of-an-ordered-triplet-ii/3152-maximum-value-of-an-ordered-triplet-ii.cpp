class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       vector<int> leftMax(nums.size(),0);
       vector<int> rightMax(nums.size(),0);
       int maxElem = 0;
       
       for(int i = 0; i < nums.size();i++){
            maxElem = max(nums[i], maxElem);
            leftMax[i] = maxElem;
        }
        maxElem = 0; 

        for(int j = nums.size()-1; j >= 0; j--){
            maxElem = max(nums[j], maxElem);
            rightMax[j] = maxElem;
        }

        long long ans = 0;

        for (int k = 1; k < nums.size() - 1; k++) {
            long long val = 1LL * (leftMax[k - 1] - nums[k]) * rightMax[k + 1];
            ans = max(ans, val);
        }
 
        if(ans < 0){
            return 0;
        }

        return ans;
    }
};