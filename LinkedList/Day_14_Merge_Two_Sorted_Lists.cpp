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


// Striver's Approach
// cleaner

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
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val <= list2 -> val){
                temp -> next = list1;
                list1 = list1 -> next;
            } else{
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }

        if(list1 != NULL){
            temp -> next = list1;
        }

        if(list2 != NULL){
            temp -> next = list2;
        }

        return dummyNode -> next;
    }
};
