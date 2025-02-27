class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int left_product = 1;
        int right_product = 1;

        for(int i = 0; i < nums.size(); i++){
            answer[i] *= left_product;
            left_product *= nums[i];
        }

        for(int j = nums.size()-1; j >= 0; j--){
            answer[j] *= right_product;
            right_product *= nums[j];
        }

        return answer;

    }
};