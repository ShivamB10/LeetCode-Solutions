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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == nullptr) return ans;
        
        queue <TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int lvl = nodes.size();
            vector<int> levels;

            for(int i = 0; i < lvl; i++){
                TreeNode *temp = nodes.front();

                if(temp->left !=nullptr){
                    nodes.push(temp->left);
                }
                if(temp->right !=nullptr){
                    nodes.push(temp->right);
                }
                levels.push_back(temp->val);
                nodes.pop();
            }

            ans.push_back(levels);
        }

        return ans;
    }
};