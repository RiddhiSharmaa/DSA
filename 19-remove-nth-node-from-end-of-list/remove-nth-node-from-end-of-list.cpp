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
    ListNode* reverseList(ListNode* head){
        if (!head) return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr){
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = reverseList(head);
        if (n == 1){
            ListNode* toDelete = temp;
            temp = temp -> next;
            toDelete -> next = nullptr;
            delete(toDelete);
            ListNode* ans = reverseList(temp);
            return ans;
        }
        int i = 0;
        ListNode* dummy = temp;
        ListNode* prev = temp;

        while (i < n-1){
            prev = temp;
            temp = temp -> next;
            i++;
        }

        prev -> next = temp -> next;
        temp -> next = nullptr;

        delete(temp);
        if (!dummy) return nullptr;
        ListNode* t = reverseList(dummy);
        
        return t;
    }
};