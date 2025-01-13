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
    int maxDiameter(TreeNode* root, int &diameter){
        if (root == nullptr) return 0;
        int depthLeft= maxDiameter(root->left, diameter);
        int depthRight = maxDiameter(root->right, diameter);

        diameter = std::max(diameter, depthLeft + depthRight);

        return std::max(1+depthLeft, 1+ depthRight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        maxDiameter(root, diameter);

        return diameter;
    }
};