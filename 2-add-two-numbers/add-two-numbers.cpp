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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int sum,carry=0;

        while (list1 != NULL || list2 != NULL || carry != 0) 
        {
            sum = carry;
            if(list1 != NULL)
            {
                sum += list1 -> val;
                list1 = list1 -> next;
            }
            if(list2 != NULL)
            {
                sum += list2 -> val;
                list2 = list2 -> next;
            }
            carry = sum / 10;
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
        }
        return dummy -> next;
    }
};