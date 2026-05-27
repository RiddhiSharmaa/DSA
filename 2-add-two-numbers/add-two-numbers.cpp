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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode(0);
        ListNode* dummy = prev;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr){
            int n1 = l1 ? l1 -> val : 0;
            int n2 = l2 ? l2 -> val : 0;
            int sum = n1 + n2 + carry;
            int n = sum % 10;
            carry = sum / 10;

            prev -> next = new ListNode(n);
            prev = prev -> next;
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }

        if (carry){
            prev -> next = new ListNode(carry);
            prev = prev -> next;
        }

        return dummy -> next;
    }
};