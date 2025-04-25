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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        while(numsSet.find(head->val)!= numsSet.end()){
            head= head->next;
        }

        if(head == nullptr){
            return nullptr;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){
            if(numsSet.find(curr->val)!= numsSet.end()){
                curr = curr->next;
                prev->next = curr;
            }
            else{
                prev= curr;
                curr=curr->next;
            }
        }


        return head;

        
        



    }
};