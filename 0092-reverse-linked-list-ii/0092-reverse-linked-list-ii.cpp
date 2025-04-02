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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        vector<int> arr;
        ListNode* curr = head;

        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }

        left--;
        right--;
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }


        curr = head;
        int i = 0;

        while(head){
            if(head->val!= arr[i]){
                head->val = arr[i];
            }
            head= head->next;
            i++;
        }

        return curr;

    }
};