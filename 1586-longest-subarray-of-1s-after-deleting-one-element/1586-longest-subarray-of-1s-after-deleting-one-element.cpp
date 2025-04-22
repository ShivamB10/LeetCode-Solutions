class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;

        int start = 0;
        int maxLength = 0; 

        for(int end = 0; end < nums.size(); end++){
            freq[nums[end]]++;

            if(freq[1] == nums.size()){
                return nums.size()-1;
            }


            if(freq[0]>1){
                freq[nums[start]]--;
                start++;
            }

            maxLength = max(maxLength, freq[1]);
        }

        return maxLength;
    }
};