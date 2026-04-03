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
    ListNode* reverse(ListNode* slow){
        ListNode* temp = slow;
        ListNode* prev = nullptr;
        while (temp != nullptr){
            ListNode* nextNode = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = nextNode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* temp = reverse(slow);
        fast = head;

        while (fast && temp && fast -> val == temp -> val){
            temp = temp -> next;
            fast = fast -> next;
        }

        if (fast && temp && fast -> val != temp -> val) return false;

        return true;
    }
};