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
    
    int minDepth(TreeNode* root) {
        int minHeight = 0;
        int left = 0;
        int right = 0;
        
        if(root == nullptr){
            return 0;
        }

        left = minDepth(root->left);
        right = minDepth(root->right);


        if(root->left == nullptr || root->right == nullptr){
            return left+right+1;
        }


        minHeight = std::min(left,right);

        return minHeight + 1;


    }
};