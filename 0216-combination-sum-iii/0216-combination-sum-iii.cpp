class Solution {
public:
     void comboGenerate(vector<int> &combArr, vector<vector<int>>&ans, vector<int>&combo, int k, int n, int currSum, int index){
        if(currSum == n && combo.size() == k){
            ans.push_back(combo);
            return;
        }

        if(index > combArr.size() || currSum > n || combo.size() > k){
            return;
        }

        currSum+= combArr[index];
        combo.push_back(combArr[index]);
        comboGenerate(combArr, ans, combo, k, n, currSum, index+1);

        currSum-= combArr[index];
        combo.pop_back();
        comboGenerate(combArr, ans, combo, k, n, currSum, index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combArr;
        for(int i =0; i < 9; i++){
            combArr.push_back(i+1);
        }

        vector<vector<int>> ans;
        vector<int> combo;
        int currSum = 0;

        comboGenerate(combArr, ans, combo, k, n, currSum, 0);

        return ans;

        
    }
};