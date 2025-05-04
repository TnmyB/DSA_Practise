// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// Brute - 2 loops, to check presence of 1 element in another array

// Better - use hash set to store each node of one list, iterate through the elements of list2 and look for any element in list1

// Optimal - 1
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 1;
        int countB = 1;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != NULL){
            tempA = tempA -> next;
            countA++;
        }
        while(tempB != NULL){
            tempB = tempB -> next;
            countB++;
        }

        if(countA>countB){
            int diff = countA - countB;
            while(diff != 0){
                headA = headA -> next;
                diff--;
            }
        } else if(countA<countB){
            int diff = countB - countA;
            while(diff != 0){
                headB = headB -> next;
                diff--;
            }
        }

        while(headA!=NULL && headB!=NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};

// Optimal - 2
// Striver's
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB == NULL){
            return NULL;
        }
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b){
            a = a == NULL? headB: a -> next;
            b = b == NULL? headA: b -> next;
        }
        return a;
    }
};
