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
    void pathSum(TreeNode* root, string path, vector<string>& sum){
        if(root == nullptr){
            return ;
        };

        if(root->left == nullptr && root->right == nullptr){
            path.append(to_string(root->val));
            sum.push_back(path);
        }

        else{
            path.append(to_string(root->val));
            pathSum(root->left, path,sum);
            pathSum(root->right, path,sum);

        }
    }

    int sumNumbers(TreeNode* root) {
        string path;
        vector<string> sum;

        pathSum(root,path,sum);

        int total = 0;

        for(int i = 0; i < sum.size(); i++){
            total += stoi(sum[i]);
        }

        return total;

    }
};