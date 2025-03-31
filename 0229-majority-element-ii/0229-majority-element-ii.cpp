class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int votes1 = 0;
        int votes2 = 0;

        int candidate1 = -1;
        int candidate2 = -1;

        int i = 0;

        for (int num : nums) {
            if (num == candidate1) {
                votes1++;
            } 
            else if (num == candidate2) {
                votes2++;
            } 
            else if (votes1 == 0) {
                candidate1 = num;
                votes1 = 1;
            } 
            else if (votes2 == 0) {
                candidate2 = num;
                votes2 = 1;
            } 
            else {
                votes1--;
                votes2--;
            }
        }

        int count1 = 0;
        int count2 = 0;

        for(i = 0; i < nums.size(); i++){
            if(candidate1 == nums[i]){
                count1++;
            }

            else if(candidate2 == nums[i]){
                count2++;
            }
        }

        if(count1 > nums.size()/3){
            ans.push_back(candidate1);
        }

        if(candidate1 != candidate2 && count2 > nums.size()/3){
            ans.push_back(candidate2);
        }

        return ans;

    }
};