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
    int maxDepth(TreeNode *root, bool &balanced){
        if(root == nullptr){
            return 0;
        }

        int heightL = maxDepth(root->left, balanced);
        int heightR = maxDepth(root->right, balanced);

        if(abs(heightL-heightR) > 1){
            balanced = false;
        }   

        return 1 + max(heightL, heightR);
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        
        maxDepth(root, balanced);

        return balanced;
    }
};