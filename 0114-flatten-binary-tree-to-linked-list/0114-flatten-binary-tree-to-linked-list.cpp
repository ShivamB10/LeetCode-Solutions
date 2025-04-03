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
    void traversePre(TreeNode* root, vector<int>& traverse){
        if(root == nullptr){
            return;
        }
        traverse.push_back(root->val);
        traversePre(root->left, traverse);
        traversePre(root->right, traverse);
    }

    void mergeNode(TreeNode* root, vector<int>& traverse, int index){
        if(index > traverse.size()|| root == nullptr){
            return;
        }

        root->val = traverse[index];
        root->left = nullptr;

        if(index + 1 < traverse.size()){
            root->right = new TreeNode(0);
            mergeNode(root->right, traverse, index+1);
        }
        
    }

    void flatten(TreeNode* root) {
        vector<int> traverse;
        traversePre(root,traverse);
        mergeNode(root,traverse,0);
    }
};