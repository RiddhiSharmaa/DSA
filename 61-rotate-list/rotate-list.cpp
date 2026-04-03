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
    int getLen(ListNode* temp){
        int len = 0;
        while (temp != nullptr){
            temp = temp -> next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        int len = getLen(head);
        k %= len;
        len -= k;

        ListNode* temp = head;
        while (temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = head;

        temp = head;
        for (int i = 1; i < len; i++){
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = nullptr;

        return head;
    }
};