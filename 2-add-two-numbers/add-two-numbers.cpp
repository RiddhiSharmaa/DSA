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
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (t1 != nullptr || t2 != nullptr){
            int n1 = t1 ? t1 -> val : 0;
            int n2 = t2 ? t2 -> val : 0;
            int n = n1 + n2 + carry;
            int num = n % 10;
            carry = n / 10;

            ListNode* node = new ListNode(num);
            temp -> next = node;
            temp = temp -> next;
            t1 = t1 ? t1 -> next : nullptr;
            t2 = t2 ? t2 -> next : nullptr;
        }

        if (carry > 0){
            ListNode* k = new ListNode(carry);
            temp -> next = k;
            k = k -> next;
        }

        return dummy -> next;
    }
};