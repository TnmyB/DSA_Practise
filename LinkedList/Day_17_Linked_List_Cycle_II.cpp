// https://leetcode.com/problems/linked-list-cycle-ii/description/

// Approach - 1
// Brute -
// Use hashmap, hash all nodes and see if there is a match
// TC = O(n)
// SC = O(n)



// Approach - 2
// slow fast algorithm
// TC = O(n)
// SC = O(1)
//
// Intution:
// Slow = L1 + L2
// Fast = L1 + L2 + nC
// fast = 2 * slow
// L1 + L2 + nC = 2*L1 + 2*L2
// nC = L1 + L2
// L1 = nC - L2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast){
                break;
            }
        }

        if(fast == NULL || fast -> next == NULL){
            return NULL;
        }

        ListNode* restart = head;
        while(restart != slow){
            restart = restart -> next;
            slow = slow -> next;
        }
        return restart;
    }
};
