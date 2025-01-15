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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> indices;
        for(int i = 0; i<inorder.size(); i++){
            indices[inorder[i]] = i;
        }

        int rootIndex = 0;


        return build(preorder, indices, rootIndex, 0, inorder.size()-1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map <int,int> &indices, int &rootIndex, int left, int right){
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[rootIndex]);
        int mid = indices[preorder[rootIndex]];
        rootIndex++;

        root->left = build(preorder, indices, rootIndex, left, mid-1);
        root->right = build(preorder, indices, rootIndex, mid +1, right);

        return root;
    }
};