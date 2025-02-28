class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start <= end){
            mid = start + (end - start)/2;

            if(target == nums[mid]){
                return mid;
            }

            else if(nums[mid] >= nums[0]){
                if(nums[start] <= target && nums[mid] > target){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }

            else if(nums[mid] < nums[0]){
                if(nums[mid] < target && nums[end] >= target){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};