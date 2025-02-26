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
    void populateStack(ListNode* l, stack<int>& list){
        if(l == nullptr){
            return;
        }

        list.push(l->val);

        populateStack(l->next,list);
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> list1;
        stack<int> list2;
        stack<int> result;
        ListNode* ans = nullptr;
        
        int carry = 0;

        populateStack(l1,list1);
        populateStack(l2,list2);

        while(!list1.empty() || !list2.empty() || carry){
            int total = carry;
            if(!list1.empty()){
                total+= list1.top();
                list1.pop();
            }

            if(!list2.empty()){
                total+= list2.top();
                list2.pop();
            }

            int num = total%10;
            carry = total/10;

            
            ListNode* res = new ListNode(num);
            res->next = ans;
            ans = res;

        }

        return ans;



        

    }
};