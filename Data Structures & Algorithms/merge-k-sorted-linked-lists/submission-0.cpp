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
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
        ListNode dummy = ListNode(0);
        ListNode * result = &dummy;
        while (l1 && l2){
            if (l1->val < l2->val){
                result->next = l1;
                l1=l1->next;
            } else {
                result->next = l2;
                l2=l2->next;
            }
            result = result->next;

        }
        result->next = l1 ? l1 : l2;
        return dummy.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) return nullptr;
        while (lists.size() > 1){
            vector<ListNode*> mergedList;
            for (int i=0; i<lists.size(); i+=2){
                ListNode * l2 = (i+1 == lists.size()) ? nullptr : lists[i+1];
                mergedList.push_back(mergeTwoLists(lists[i], l2));
            }
            lists = mergedList;

        }
        return lists[0];

        
    }
};
