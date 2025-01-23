/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNode(ListNode* head,ListNode *curr, ListNode *prev,int val){
        if(curr == nullptr){
            return head;
        }

        if(curr->val == val){
            prev->next = curr->next;
            curr = curr->next;
            return removeNode(head,curr,prev,val);
        }

        else{
            return removeNode(head,curr->next,curr,val);
            }
    };
    ListNode* removeElements(ListNode* head, int val) {
        while(head!= nullptr and head->val == val){
            head = head->next;
        }
        
        if(head == nullptr){
            return nullptr;
        }

        

        ListNode *curr = head->next;
        ListNode *prev = head;

        return removeNode(head,curr,prev,val);

        


        
    }
};