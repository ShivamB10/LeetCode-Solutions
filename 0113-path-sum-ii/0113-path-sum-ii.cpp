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
    vector<vector<int>> ans;
    vector<int> path;

private:
    vector<vector<int>> validPath(TreeNode* root, int targetSum){
        if(root == nullptr){
            return ans;
        }
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && targetSum - root->val == 0){
            ans.push_back(path);
        }

        else{
            validPath(root->left, targetSum - root->val);
            validPath(root->right, targetSum - root->val);
        }

        path.pop_back();

        return ans;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return {};
        }

        return validPath(root, targetSum);

    }
};