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
    bool validity(TreeNode* root, long long int valMin, long long int valMax){
        if(root == nullptr){
            return true;
        }

        if(root->val >= valMax || root->val <= valMin){
            return false;
        }

        return validity(root->left,valMin,root->val) && validity(root->right,root->val,valMax);
    }

    bool isValidBST(TreeNode* root) {
        long long int valMin = LLONG_MIN;
        long long int valMax = LLONG_MAX;

        return validity(root,valMin,valMax);
    }
};