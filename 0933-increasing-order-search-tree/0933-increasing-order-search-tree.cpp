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
    void traversalTree(TreeNode* root, stack<TreeNode*>& dfs){
        if(root == nullptr){
            return;
        }

        traversalTree(root->right,dfs);
        dfs.push(root);
        traversalTree(root->left,dfs);

        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> dfs;
        traversalTree(root,dfs);

        TreeNode* newRoot = dfs.top();
        dfs.pop();
        TreeNode* curr = newRoot;
        while(!dfs.empty()){
            TreeNode* Nodecurr = dfs.top();
            dfs.pop();
            curr->right = Nodecurr;
            curr = Nodecurr;
            curr->left = nullptr;
        }


        return newRoot;

    }
};