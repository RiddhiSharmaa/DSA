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
    ListNode* reverseList(ListNode* mid){
        ListNode* curr = mid;
        ListNode* prev = nullptr;

        while (curr != nullptr){
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = findMid(head);
        ListNode* m = slow -> next;

        slow -> next = nullptr;
        ListNode* mid = reverseList(m);

        ListNode* temp = head;

        while (mid != nullptr){
            ListNode* nextNode2 = mid -> next;
            ListNode* nextNode1 = temp -> next;
            temp -> next = mid;
            mid -> next = nextNode1;
            temp = nextNode1;
            mid = nextNode2;
        }

        return;
    }
};