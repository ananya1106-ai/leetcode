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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // step 1 (find mid element)
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* prev = slow;
        slow = slow -> next;
        prev -> next = NULL;
        // step 2 (reverse 2nd half)
        while(slow != NULL)
        {
            ListNode* temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }
        // step 3 (two pointer)
        ListNode* p1= head;
        ListNode* p2= prev;
        while(p2 != NULL)
        {
            if(p1 -> val != p2 -> val)
            {
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return true;
    }
};