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
    int count = 0;
    int countNodes(TreeNode* root, int currentMax){
        if(root == nullptr){
            return 0;
        }
        
        if(root->val >= currentMax){
            count++;
            currentMax = root->val;
        }
        
        countNodes(root->left, currentMax);
        countNodes(root->right, currentMax);

        return count;

    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        return countNodes(root, root->val);
    }
};