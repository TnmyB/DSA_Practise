// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// My Approach

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* headPtr = new ListNode();
        headPtr -> next = head;

        ListNode* temp = head;
        ListNode* turn = head;
        ListNode* curHead = turn;
        ListNode* prev = temp;
        ListNode* next;
        ListNode* prevHead = headPtr;
        while(temp!=NULL){
            for(int i = 0; i< k; i++){
                if(temp == NULL){
                    return headPtr;
                }
                temp = temp -> next;
            }

            curHead = turn;
            
            while(turn != temp){
                next = turn -> next;
                if(turn == curHead){
                    turn -> next = temp;
                } else{
                    turn -> next = prev;
                }
                prev = turn;
                turn = next;
            }

            prevHead -> next = prev;
            prevHead = curHead;
            if(curHead == head){
                headPtr = prev;
            }
        }

        return headPtr;
    }
};



// Striver's
// TC = O(n)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k ==1 ){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int count = 0;
        ListNode *cur = dummy;
        ListNode *nex = dummy;
        ListNode *pre = dummy;

        while(cur -> next != NULL){
            cur = cur -> next;
            count++;
        }

        while(count >= k){
            cur = pre -> next;
            nex = cur -> next;
            for(int i = 1; i < k; i++){
                cur -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = cur -> next;
            }
            pre = cur;
            count -= k;
        }

        return dummy->next;
    }
};
