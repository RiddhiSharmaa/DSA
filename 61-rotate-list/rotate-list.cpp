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
    int getLen(ListNode* head){
        int len = 0;
        while (head){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        if (k == 0) return head;
        int len = getLen(head);
        k %= len;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr -> next){
            curr = curr -> next;
        }

        curr -> next = head;
        
        int i = 1;
        while (i <= len-k){
            prev = temp;
            temp = temp -> next;
            i++;
        }

        prev -> next = nullptr;

        return temp;
    }
};