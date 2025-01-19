class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right_pointer = 1;
        int unique;
        if(nums.size() == 1){
            return nums[0];
        }
        for(int left_pointer = 0; left_pointer < nums.size() -2; left_pointer++){
            if(nums[left_pointer] == nums[right_pointer]){
                left_pointer = left_pointer + 1;
                right_pointer = right_pointer + 2;
            }
            else {
                unique = nums[left_pointer];
                break;
            }
        }

        return unique;
    }
};