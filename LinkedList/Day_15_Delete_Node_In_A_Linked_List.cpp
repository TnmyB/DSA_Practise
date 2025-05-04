// https://leetcode.com/problems/delete-node-in-a-linked-list/description/


// Dumb ways to die - over engineered solution
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
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node -> next;
        while(nextNode->next != NULL){
            node -> val = nextNode -> val;
            node = node -> next;
            nextNode = nextNode -> next;
        }
        node -> val = nextNode -> val;
        node -> next = nextNode -> next;

    }
};

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
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
