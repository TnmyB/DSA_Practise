// https://leetcode.com/problems/rotate-list/description/
// TC = O(N) + O(N - N%k) ~ O(N)
// SC = O(1)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        int len = 1;
        ListNode *end = head;
        while(end -> next != NULL){
            end = end -> next;
            len++;
        }

        int splitPoint = len - ( k % len) - 1;
        ListNode *newEnd = head;
        while(splitPoint != 0){
            newEnd = newEnd -> next;
            splitPoint--;
        }

        end -> next = head;
        head = newEnd -> next;
        newEnd -> next = NULL;

        return head;
    }
};
