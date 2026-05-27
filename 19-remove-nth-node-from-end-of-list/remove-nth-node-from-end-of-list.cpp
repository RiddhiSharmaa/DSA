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
    int getLength(ListNode* node){
        int cnt = 0;
        while (node != nullptr){
            cnt++;
            node = node -> next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int getLen = getLength(head);
        int k = getLen - n;
        if (k == 0) return head -> next;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 0;

        while (cnt < k){
            prev = temp;
            temp = temp -> next;
            cnt++;
        }

        if (prev) prev -> next = temp -> next;

        temp -> next = nullptr;

        return head;
    }
};