class Solution {
public:
    void constructCombo(vector<vector<int>>& ans,vector<int>& combo, vector<int>& candidates, int n, int k, int index){
        if(combo.size()==k && index <= n){
            ans.push_back(combo);
            return;
        }

        if(combo.size() > k || index >= n){
            return;
        }

        combo.push_back(candidates[index]);
        constructCombo(ans,combo,candidates,n,k,index+1);

        combo.pop_back();
        constructCombo(ans,combo,candidates,n,k,index+1);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> candidates;
        vector<vector<int>> ans;
        vector<int> combo;
        for(int i = 0; i < n; i++){
            candidates.push_back(i+1);
        }

        constructCombo(ans,combo,candidates,n,k,0);

        return ans;


    }
};