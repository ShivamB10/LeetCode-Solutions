class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int candidate = -1;
        int votes = 0;
        int i = 0;
        for(i = 0; i < nums.size(); i++){
            if(votes == 0){
                candidate = nums[i];
                votes++;
            }
            else{
                if(nums[i] == candidate){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }

        int total_count = 0;

        for(i = 0; i < nums.size(); i++){
            if(candidate == nums[i]){
                total_count++;
            }
        }

        if(total_count <= nums.size()/2){
            return -1;
        }


        int left_count = 0;

        for(i = 0; i < nums.size(); i++){
            if(candidate == nums[i]){
                left_count++;
            }

            int left_size = i+1;
            int right_size = nums.size() - left_size;
            int right_count = total_count - left_count;

            if(left_count*2 > left_size && right_count*2 > right_size){
                return i;
            }

        }

        return -1;
        
        
    }
};