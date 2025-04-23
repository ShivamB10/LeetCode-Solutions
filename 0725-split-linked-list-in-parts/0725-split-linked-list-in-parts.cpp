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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        vector<ListNode*> ans;
        
        while(curr){
            count++;
            curr = curr->next;
        }

        int extraCount = count%k;
        int partSize = count/k;

        curr = head;

        for(int i = 0; i < k; i++){
            int sizePart = partSize;
            if(extraCount > 0){
                sizePart++;
            }
            extraCount--;

            if(sizePart == 0){
                ans.push_back(nullptr);
                continue;
            }

            ListNode* partHead = curr;

            for(int j = 0; j < sizePart - 1 && curr; j++){
                curr = curr->next;
            }
            if(curr){
                ListNode* next = curr->next;
                curr->next = nullptr;
                curr = next;
            }
            

            ans.push_back(partHead);

    

        }


    return ans;

    }
};