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

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;

        while (head != nullptr){
            if (head -> next != nullptr && head -> next  -> val == head -> val){
                int value = head -> val;

                while (head && head -> val == value){
                    ListNode* temp = head;
                    head = head -> next;
                    temp -> next = nullptr;
                    delete temp;
                }

                prev -> next = head;
            } else {
                prev = head;
                head = head -> next;
            }
        }

        return dummy -> next;
    }
};