/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1-> next != nullptr){
            t1 = t1 -> next;
        }

        t1 -> next = t2;

        ListNode* slow = headA;
        ListNode* fast = headA;
        bool cycle = false;

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow){
                cycle = true;
                slow = headA;
                break;
            }
        }

        if (!cycle) {
            t1 -> next = nullptr;
            return nullptr;
        }

        while (fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }

        t1 -> next = nullptr;

        return slow;
    }
};