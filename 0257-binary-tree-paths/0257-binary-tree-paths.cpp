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
    void constructPath(TreeNode* root, vector<string>& ans,string path){
        if(root == nullptr){
            return ;
        }

        if(root->left == nullptr && root->right == nullptr){
            path.append(to_string(root->val));
            ans.push_back(path);
            
        }

        else{
            path.append(to_string(root->val));
            path.append("->");
            constructPath(root->left,ans,path);
            constructPath(root->right,ans, path);
        }



    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        constructPath(root,ans,path);

        return ans;

    }
};