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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp = head;

        while (temp -> next != nullptr){
            ListNode* nextNode = temp -> next;
            if (nextNode -> val == temp -> val){
                temp -> next = nextNode -> next;
                nextNode -> next = nullptr;
                delete(nextNode);
                continue;
            }
            temp = temp -> next;
        }

        return head;
    }
};