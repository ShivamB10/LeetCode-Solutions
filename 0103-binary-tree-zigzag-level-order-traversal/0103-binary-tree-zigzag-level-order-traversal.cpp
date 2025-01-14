/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue <TreeNode* > q;
        q.push(root);
        int alternate = 1;

        while(!q.empty()){
            int levels = q.size();
            vector<int> lvl;

            for(int i = 0; i < levels; i++){
                TreeNode * temp = q.front();

                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right !=nullptr){
                    q.push(temp->right);
                };

                lvl.push_back(temp->val);
                q.pop();
            }

            if(alternate%2 == 0){
                reverse(lvl.begin(), lvl.end());
            }
            
            alternate = alternate + 1;

            ans.push_back(lvl);

        }

        return ans;
    }
};