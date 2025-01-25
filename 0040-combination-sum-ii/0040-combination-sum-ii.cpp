class Solution {
public:
    void constructCombo(vector<int>& candidates,int target,int index,int currSum, vector<vector<int>>& ans, vector<int>& combo ){
        if(currSum == target){
            if(ans.empty() || ans.back() != combo){
                ans.push_back(combo);
            }
            return;
        }
        if(currSum > target || index >= candidates.size()){
            return;
        }

        currSum += candidates[index];
        combo.push_back(candidates[index]);
        constructCombo(candidates,target,index+1,currSum,ans,combo);

        while(index + 1 < candidates.size() && candidates[index] == candidates[index+1]){
            index+=1;
        }

        currSum -= candidates[index];
        combo.pop_back();
        constructCombo(candidates,target,index+1,currSum,ans,combo);
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;
        int currSum = 0;

        constructCombo(candidates,target,0,currSum,ans,combo);

        return ans;
    }
};