class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_two;
        int max_len = 0;
        for(int i = 0; i < nums.size();i++){
            nums_two.insert(nums[i]);
        }

        for(auto it = nums_two.begin(); it != nums_two.end(); ++it){
            int curr_num = *it;
            int curr_len = 1;
            if(nums_two.find(curr_num -1) != nums_two.end()){
                continue;
            }
            while(nums_two.find(curr_num+1) != nums_two.end()){
                curr_num++;
                curr_len++;
            }

            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};