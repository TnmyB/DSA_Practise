/*
    Title - Flattening a Linked List
    Link - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode* mergeTwoNodes(ListNode* a, ListNode* b){
        ListNode *temp = new ListNode(0);
        ListNode *res = temp;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                temp -> child = a;
                temp = temp -> child;
                a = a -> child;
            } else{
                temp -> child = b;
                temp = temp -> child;
                b = b -> child;
            }
        }
        if(a!=NULL){
            temp -> child = a;
        }

        if(b!=NULL){
            temp -> child = b;
        }

        return res -> child;
    }

    ListNode* flattenLinkedList(ListNode* &head) {
        if(head==NULL || head -> next == NULL){
            return head;
        }
        head -> next = flattenLinkedList(head -> next);
        head = mergeTwoNodes(head, head -> next);
        return head;
    }
};
