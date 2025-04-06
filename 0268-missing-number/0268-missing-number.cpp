class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size()-1;
        int ans = nums.size();

        while(start<= end){
            int mid = start + (end-start)/2;
            

            if(mid == nums[mid]){
                start = mid+1;
            }

            else{
                end = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};