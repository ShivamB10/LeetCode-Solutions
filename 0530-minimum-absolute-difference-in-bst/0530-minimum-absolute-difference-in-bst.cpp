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
    void traverse(TreeNode* root, vector<int>&dfs){
        if(root == nullptr){
            return;
        }

        traverse(root->left,dfs);
        dfs.push_back(root->val);
        traverse(root->right,dfs);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> dfs;
        traverse(root,dfs);
        int mindist = INT_MAX;

        for(int i = 1; i < dfs.size(); i++){
            mindist = min(mindist, dfs[i] - dfs[i-1]);
        }

        return mindist;
    }
};