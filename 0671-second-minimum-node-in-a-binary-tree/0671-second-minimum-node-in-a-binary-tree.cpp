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
    void secondMinimum(TreeNode* root, int min, long long int& secondMin){
        if(root == nullptr){
            return ;
        }

        if(root->val > min && root->val < secondMin){
            secondMin = root->val;
        }

        secondMinimum(root->left,min,secondMin);
        secondMinimum(root->right,min,secondMin);

        return;


    }
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        long long int secondMin = LLONG_MAX;

        secondMinimum(root, min, secondMin);

        if(secondMin == LLONG_MAX){
            return -1;
        }
        
        return secondMin;
        
    }
};