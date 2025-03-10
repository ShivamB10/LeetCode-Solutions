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
    struct Compare{
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(!pq.empty()){
            ListNode* minNode = pq.top();
            pq.pop();
            if(minNode->next){
                pq.push(minNode->next);
            }
            dummy->next = minNode;
            dummy = dummy->next;
        }


        return ans->next;
        
    }
};