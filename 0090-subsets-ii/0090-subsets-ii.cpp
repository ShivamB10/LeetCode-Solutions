class Solution {
public:
    void constructSubset(vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans,int index){
        if(index == nums.size()){
            if(ans.empty() || ans.back() != subset){
                ans.push_back(subset);
            }
            return;
        }
        
        subset.push_back(nums[index]);
        constructSubset(nums,subset,ans,index+1);

        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index += 1;
        }
        subset.pop_back();
        constructSubset(nums,subset,ans,index+1);

        }

    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        constructSubset(nums,subset,ans,0);
        return ans;

    }
};