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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        int i = 0;
        while (i < n){
            fast = fast -> next;
            i++;
        }

        while (fast -> next != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* toDelete = slow -> next;
        slow -> next = toDelete -> next;
        toDelete -> next = nullptr;
        delete(toDelete);

        return dummy -> next;
    }
};