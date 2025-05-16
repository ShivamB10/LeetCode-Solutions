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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int n = bfs.size();
            int max_val = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* curr = bfs.front();
                max_val = max(max_val, curr->val);

                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }

                bfs.pop();
            }

            ans.push_back(max_val);
        }


        return ans;
    }
};