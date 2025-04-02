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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* trav = head;
        vector<int> arr;
        while(trav){
            arr.push_back(trav->val);
            trav = trav->next;
        }

        swap(arr[k-1], arr[arr.size()-k]);

        trav = head;
        int i = 0;
        while(trav){
            if(trav->val != arr[i]){
                trav->val = arr[i];
            }
            trav = trav->next;
            i++;
        }


        return head;
    }
};