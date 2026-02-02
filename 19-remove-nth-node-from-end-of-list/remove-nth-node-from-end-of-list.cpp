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
    int countLen(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;

        while (temp != nullptr){
            temp = temp -> next;
            cnt++;
        }

        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        int len = countLen(head);

        int cnt = len - n;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        int i = 0;
        while (i < cnt){
            prev = temp;
            temp = temp -> next;
            i++;
        }

        if (prev == nullptr){
            ListNode* h = head -> next;
            delete head;
            return h;
        }

        prev -> next = temp -> next;
        delete temp;

        return head;
    }
};