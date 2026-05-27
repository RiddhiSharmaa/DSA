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
        ListNode* carry = new ListNode(0);
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (l1 && l2){
            int n = l1 -> val + l2 -> val + carry -> val;
            int num = n % 10;
            carry -> val = n / 10;

            ListNode* newNode = new ListNode(num);
            temp  -> next = newNode;
            temp = temp -> next;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while (l1){
            int n = l1 -> val + carry -> val;
            int num = n % 10;
            carry -> val = n / 10;

            ListNode* newNode = new ListNode(num);
            temp -> next = newNode;
            temp = temp -> next;

            l1 = l1 -> next;
        }

        while (l2){
            int n = l2 -> val + carry -> val;
            int num = n % 10;
            carry -> val = n / 10;

            ListNode* newNode = new ListNode(num);
            temp  -> next = newNode;
            temp = temp -> next;

            l2 = l2 -> next;
        }

        if (carry -> val > 0){
            ListNode* newNode = new ListNode(carry -> val);
            temp -> next = newNode;
            temp = temp -> next;
        }

        return dummy -> next;
    }
};