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
        ListNode* prev = new ListNode();
        ListNode* dummy = prev;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr){
            int n1 = l1 ? l1 -> val : 0;
            int n2 = l2 ? l2 -> val : 0;
            int n = n1 + n2 + carry;
            carry = n/10;
            int digit = n%10;
            prev -> next = new ListNode(digit);
            prev = prev -> next;
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }

        while (carry){
            int digit = carry%10;
            prev -> next = new ListNode(digit);
            prev = prev -> next;
            carry /= 10;
        }

        return dummy -> next;
    }
};