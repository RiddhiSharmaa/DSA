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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp){
            ListNode* curr = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = curr;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* temp = reverse(slow);
        fast = head;

        while (temp){
            if (fast -> val != temp -> val) return false;
            temp = temp -> next;
            fast = fast -> next;
        }

        return true;
    }
};