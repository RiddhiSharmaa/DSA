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
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = nullptr;
        ListNode* dummy = new ListNode(0);

        if (temp1 -> val < temp2 -> val){
            head = temp1;
            temp1 = temp1 -> next;
        } else{
            head = temp2;
            temp2 = temp2 -> next;
        }

        dummy -> next = head;
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1 -> val < temp2 -> val){
                head -> next = temp1;
                temp1 = temp1 -> next;
            } else if (temp2 -> val <= temp1 -> val){
                head -> next = temp2;
                temp2 = temp2 -> next;
            }
            head = head -> next;
        }

        if (temp1) head -> next = temp1;
        if (temp2) head -> next = temp2;

        return dummy -> next;
    }
};