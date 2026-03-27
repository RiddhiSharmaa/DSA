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
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* prev = new ListNode();
        ListNode* dummy = prev;

        while (t1 != nullptr || t2 != nullptr){
            int n1 = t1 ? t1 -> val : 0;
            int n2 = t2 ? t2 -> val : 0;
            int n = n1 + n2 + carry;
            carry = n/10;
            int digit = n%10;
            ListNode* newNode = new ListNode(digit);
            prev -> next = newNode;
            prev = newNode;
            if (t1) t1 = t1 -> next;
            if (t2) t2 = t2 -> next;
        }

        while (carry){
            int digit = carry%10;
            ListNode* newNode = new ListNode(digit);
            prev -> next = newNode;
            prev = newNode;
            carry /= 10;
        }

        return dummy -> next;
    }
};