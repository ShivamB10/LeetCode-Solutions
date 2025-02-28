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
    void traverse(TreeNode* root, string& path){
        if(root == nullptr){
            return;
        }

        path += to_string(root->val);

        if(root->left || root->right){
            path+= "(";
            traverse(root->left, path);
            path+= ")";
        }
        if(root->right){
            path += "(";
            traverse(root->right, path);
            path+=")";
        }
        
    }

    string tree2str(TreeNode* root) {
        string path;
        traverse(root,path);

        return path;
    }
};