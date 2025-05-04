// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead = new ListNode();
        ListNode* temp = resultHead;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int value = l1 -> val + l2 -> val + carry;
            temp-> next = new ListNode(value%10);
            temp = temp -> next;
            carry = value/10;
            l1 = l1 -> next;
            l2 = l2-> next;
        }

        while(l1 != NULL){
            int value = l1 -> val + carry;
            temp -> next = new ListNode(value%10);
            temp = temp -> next;
            carry = value/10;
            l1 = l1->next;
        }

        while(l2 != NULL){
            int value = l2 -> val + carry;
            temp -> next = new ListNode(value%10);
            temp = temp -> next;
            carry = value/10;
            l2 = l2 -> next;
        }

        if(carry!=0){
            temp -> next = new ListNode(carry);
        }
        return resultHead -> next;
    }
};
