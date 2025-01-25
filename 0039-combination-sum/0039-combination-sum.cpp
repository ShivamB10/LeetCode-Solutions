class Solution {
public:
    void comboSet(vector<int>& candidates, vector<vector<int>>& ans,vector<int>& combo,int index,int target,int currSum){
        if(currSum == target){
            ans.push_back(combo);
            return;
        }

        if(currSum > target || index >= candidates.size()){
            return;
        }

        currSum += candidates[index];
        combo.push_back(candidates[index]);
        comboSet(candidates,ans,combo,index,target,currSum);

        currSum -= candidates[index];
        combo.pop_back();
        comboSet(candidates,ans,combo,index+1,target,currSum);



        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        int currSum = 0;

        comboSet(candidates,ans,combo,0,target,currSum);

        return ans;

    }
};