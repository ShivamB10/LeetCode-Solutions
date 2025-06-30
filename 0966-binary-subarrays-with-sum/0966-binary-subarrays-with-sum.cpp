class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int total_count = 0;
        int curr_sum = 0;
        int start = 0;
        unordered_map<int, int> freq;

        for(int end = 0; end < nums.size(); end++){
            curr_sum += nums[end];

            if(curr_sum == goal){
                total_count ++;
            }

            if(freq.find(curr_sum- goal) != freq.end()){
                total_count += freq[curr_sum - goal];
            }

            freq[curr_sum]++;

            
        }

        return total_count;
    }
};