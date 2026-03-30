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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;

            if (fast == slow){
                cycle = true;
                break;
            }
        }

        if (!cycle) return nullptr;
        slow = head;

        while (fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }
};