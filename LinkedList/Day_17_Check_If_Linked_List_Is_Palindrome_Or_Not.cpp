// https://leetcode.com/problems/palindrome-linked-list/description/

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
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* prev = NULL;
        ListNode* temp = slow -> next;

        while(temp != NULL){
            ListNode* nex = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = nex;
        }
        slow -> next = prev;

        ListNode* start = head;
        ListNode* midStart = slow -> next;
        while(midStart != NULL){
            if(start->val != midStart -> val){
                return false;
            }
            start = start -> next;
            midStart = midStart -> next;
        }
        return true;
    }
};
