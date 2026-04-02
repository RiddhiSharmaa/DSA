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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1 || !list2){
            if (!list1) return list2;
            return list1;
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode();
        if (temp1 -> val < temp2 -> val){
            dummy -> next = temp1;
            temp1 = temp1 -> next;
        } else {
            dummy -> next = temp2;
            temp2 = temp2 -> next;
        }

        ListNode* t = dummy -> next;
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1 -> val < temp2 -> val){
                ListNode* nextNode = temp1 -> next;
                t -> next = temp1;
                temp1 = temp1 -> next;
            } else {
                ListNode* nextNode = temp2 -> next;
                t -> next = temp2;
                temp2 = temp2 -> next;
            }
            t = t -> next;
        }   

        if (temp1) t -> next = temp1;
        if (temp2) t -> next = temp2;   

        return dummy -> next;
    }
};