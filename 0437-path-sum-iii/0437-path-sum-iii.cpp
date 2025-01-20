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
    int helperPath(TreeNode* root, int targetSum, int& count, long long int currSum){
        if (root == nullptr){
            return count;
        }

        currSum+= root->val;

        if(targetSum == currSum){
            count++;
        }
        

        
        helperPath(root->left,targetSum , count, currSum);
        helperPath(root->right,targetSum , count, currSum);
        

        return count;
        

    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root == nullptr){
            return count;
        }
        long long int currSum = 0;

        count = helperPath(root, targetSum, count, currSum);

        count+= pathSum(root->left,targetSum);
        count+= pathSum(root->right,targetSum);

        return count;

    }
};