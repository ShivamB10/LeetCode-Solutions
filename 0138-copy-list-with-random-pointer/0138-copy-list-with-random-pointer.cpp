/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head== nullptr){
            return nullptr;
        }
        
        unordered_map<Node* , Node*> map;
        Node * curr = head;

        while(curr){
            map[curr] = new Node(curr->val);
            curr=curr->next;
        }

        Node * copyHead = map[head];

        for (auto it : map) {
        map[it.first]->next = it.first->next ? map[it.first->next] : nullptr;
        map[it.first]->random = it.first->random ? map[it.first->random] : nullptr;
    }

        return copyHead;




        

        
    }
};