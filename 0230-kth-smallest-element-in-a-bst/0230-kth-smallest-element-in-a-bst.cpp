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
    void inOrder(TreeNode* root,int& count, int& kmin){
        if (root == nullptr){
            return ;
        }

        inOrder(root->left,count,kmin);
        count--;

        if(count == 0){
            kmin = root->val;
            return;
        }

        inOrder(root->right, count,kmin);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int kmin = 0;
        inOrder(root,count,kmin);
        
        return kmin;
    }
};