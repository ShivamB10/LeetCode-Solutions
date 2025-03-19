class Solution {
public:
    void constructPermute(vector<int>& nums, int left, set<vector<int>>& ans){
        if(left == nums.size()-1){
            ans.insert(nums);
        }

        for(int i = left; i < nums.size(); i++){
            swap(nums[i],nums[left]);
            constructPermute(nums,left+1, ans);
            swap(nums[left],nums[i]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int left = 0;
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        constructPermute(nums,left,ans);
        vector<vector<int>> result(ans.begin(),ans.end());

        return result;
    }
};