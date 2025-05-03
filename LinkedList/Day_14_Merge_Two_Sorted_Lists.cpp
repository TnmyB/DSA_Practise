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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = NULL;
        if(temp1==NULL){
            return temp2;
        }

        if(temp2==NULL){
            return temp1;
        }
        
        if(temp1 -> val <= temp2 -> val){
            head = temp1;
            temp1 = temp1->next;
        } else{
            head = temp2;
            temp2 = temp2 -> next;
        }
        ListNode* resHead = head;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1 -> val <= temp2 -> val){
                head -> next = temp1;
                head = head -> next;
                temp1 = temp1 -> next;
            } else{
                head -> next = temp2;
                head = head -> next;
                temp2 = temp2 -> next;
            }
        }

        if(temp1 != NULL){
            head -> next = temp1;
        }

        if(temp2 != NULL){
            head -> next = temp2;
        }

        return resHead;
    }
};
