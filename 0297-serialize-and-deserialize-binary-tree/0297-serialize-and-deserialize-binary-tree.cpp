/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void helperSerialize(TreeNode* root, string& data){
        if(root == nullptr){
            data.append("n,");
            return ;
        }

        data.append(to_string(root->val));
        data.append(",");
        
        helperSerialize(root->left,data);
        helperSerialize(root->right,data);
        

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;

        helperSerialize(root,data);
        return data;    
    }
    
    TreeNode* helperDeserialize(string data, int& i){
            if(i < data.size() && data[i] == 'n'){
            i +=2;
            return nullptr;
            }

            string value;
            while(i < data.size() && data[i]!= ','){
                value.push_back(data[i]);
                i++;
            }
            i++;

            if(value.empty()){
                return nullptr;
            }

            TreeNode* root = new TreeNode(stoi(value));
            root->left = helperDeserialize(data,i);
            root->right = helperDeserialize(data,i);
        

            return root;

    } 

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;

        return helperDeserialize(data,i);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));