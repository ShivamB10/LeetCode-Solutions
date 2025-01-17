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
    vector<int> dfs;
    vector<int> inOrder(TreeNode* root){
        if (root == nullptr){
            return dfs;
        }

        inOrder(root->left);
        dfs.push_back(root->val);
        inOrder(root->right);

        return dfs;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector <int> ans;
        ans = inOrder(root);

        return ans[k-1];
    }
};