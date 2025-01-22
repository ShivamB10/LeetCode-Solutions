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
    int pathSum(TreeNode* root, int currSum,int& maxSum){
        if(root == nullptr){
            return 0;
        }

        int leftSum = std::max(pathSum(root->left,currSum,maxSum),0);
        int rightSum = std::max(pathSum(root->right,currSum,maxSum),0);
        
        currSum = root->val + leftSum + rightSum;
        maxSum =std::max(currSum,maxSum);


        return std::max(root->val + leftSum, root->val + rightSum);
        

    };
    int maxPathSum(TreeNode* root) {
        int currSum = 0;
        int rootSum = 0;
        int maxSum = INT_MIN;

        pathSum(root, currSum, maxSum);

        return maxSum;

       
    }
};