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
    ListNode * getKth(ListNode * curr, int k){
        while (curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode * beforeStart = &dummy;

        while (true){
            ListNode * kth = getKth(beforeStart, k);
            if (!kth) break;
            ListNode * kthNext = kth->next;

            //reverse
            ListNode * prev = kthNext;
            ListNode * curr = beforeStart->next;

            while (curr != kthNext){
                ListNode * temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode * temp = beforeStart->next;
            beforeStart->next = kth;
            beforeStart = temp;
        }
        return dummy.next;
        
        
    }
};
