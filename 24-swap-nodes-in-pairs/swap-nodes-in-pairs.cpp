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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head -> next) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head -> next;

        ListNode* t1 = head;
        ListNode* t2 = head -> next;
        ListNode* prev = nullptr;

        while (t1 && t2){
            t1 -> next = t2 -> next;
            t2 -> next = t1;
            if (prev) prev -> next = t2;
            prev = t1;
            t2 = (t1 -> next) ? t1 -> next -> next : nullptr;
            t1 = t1 -> next;
        }

        return dummy -> next;     
    }
};