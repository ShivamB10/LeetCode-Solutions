class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int prevDiff = nums[1] - nums[0];
        int count = 0;
        int start = 0;
        int current = 0;

        for(int end = 2; end < nums.size(); end++){
            if(nums[end] - nums[end - 1]!= prevDiff){
                prevDiff = nums[end] - nums[end - 1];
                start = end;
                current = 0;
            }

            else if(nums[end] - nums[end - 1] == prevDiff){
                current++;
                count += current;
            }
        }
        

        return count;
    }
};