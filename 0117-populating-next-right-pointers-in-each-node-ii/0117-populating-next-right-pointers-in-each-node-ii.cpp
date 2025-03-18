/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root == nullptr){
        return nullptr;
       }

       queue<Node* > bfs;
       bfs.push(root);


       while(!bfs.empty()){
        int size = bfs.size();
        for(int i = 0; i < size; i++){
            Node* curr = bfs.front();
            bfs.pop();
            if(i == size-1){
                curr->next = nullptr;
            }

            else{
                curr->next = bfs.front();
            }

            if(curr->left != nullptr){
                bfs.push(curr->left);
            }

            if(curr->right != nullptr){
                bfs.push(curr->right);
            }
        }
       }



       return root;
    }
};