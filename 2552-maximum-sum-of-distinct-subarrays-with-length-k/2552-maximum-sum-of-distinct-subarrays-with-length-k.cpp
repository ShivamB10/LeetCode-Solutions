class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0;
        long long max_sum = 0;
        int start = 0;

        for(int end = 0; end < nums.size(); end++){
            freq[nums[end]]++;
            while(freq[nums[end]] > 1){
                freq[nums[start]]--;
                sum -= nums[start];
                start++;
            }

            
            sum += nums[end];
            if(end - start + 1 == k){
                max_sum = max(max_sum, sum);
                freq[nums[start]]--;
                sum -= nums[start];
                start++;
            }
        }
        

        return max_sum;

       
    }
};