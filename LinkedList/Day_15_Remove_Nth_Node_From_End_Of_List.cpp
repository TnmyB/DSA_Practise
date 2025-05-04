// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


// TC = O(2*n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        
        ListNode* temp = head;
        int count = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            count++;
        }

        int prev = count - n;
        if(prev == 0){
            head = head -> next;
            return head;
        }
        count = 1;
        temp = head;
        while(count != prev){
            temp = temp -> next;
            count++;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};



// TC = O(n)
// Single Pass
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        
        ListNode* start = new ListNode();
        start -> next = head;

        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i = 1; i <= n; i++){
            fast = fast -> next;
        }

        while(fast->next!=NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

        slow -> next = slow -> next -> next;

        return start -> next;

    }
};
