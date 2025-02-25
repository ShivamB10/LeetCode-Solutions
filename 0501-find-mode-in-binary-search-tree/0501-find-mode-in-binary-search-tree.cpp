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
    void dfs(TreeNode* root, unordered_map<int,int>& count){
        if(root == nullptr){
            return;
        }

        dfs(root->left,count);
        count[root->val] += 1;
        dfs(root->right,count);

    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> count;
        dfs(root,count);
        int max_frequency = 0;

        for(auto it = count.begin(); it != count.end(); it++){
            if(it->second > max_frequency){
                max_frequency = it->second;
            }
        }

        vector<int> mode_elements;

        for(auto it2 = count.begin(); it2 != count.end(); it2++){
            if(it2->second == max_frequency){
                mode_elements.push_back(it2->first);
            }
        }

        return mode_elements;
    }
};