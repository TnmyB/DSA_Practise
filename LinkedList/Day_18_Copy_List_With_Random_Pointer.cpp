// https://leetcode.com/problems/copy-list-with-random-pointer/description/


// My Approach
// TC = O(2*n)
// SC = O(2*n)
// Can be optimized by using a single hash map mpp<Node*, Node*>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ansListHead = new Node(0);
        Node *tempAns = ansListHead;
        Node *temp = head;
        unordered_map<Node*, int> posMap;
        unordered_map<int, Node*> posMapAns;
        int pos = 1;
        while(temp != NULL){
            tempAns -> next = new Node(temp -> val);
            tempAns = tempAns -> next;
            posMap[temp] = pos;
            posMapAns[pos] = tempAns;
            pos++;
            temp = temp -> next;
        }

        tempAns = ansListHead -> next;
        temp = head;
        while(temp != NULL){
            int ansPos = posMap[temp->random];
            tempAns -> random = posMapAns[ansPos];
            temp = temp -> next;
            tempAns = tempAns -> next;
        }

        return ansListHead -> next;
    }
};

// Striver's Approach
// Insert Node in between
// TC = O(3*n)
// SC = O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        // insert new nodes in between with same values
        while(temp != NULL){
            Node *newNode = new Node(temp -> val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = newNode -> next;
        }

        // point random of new nodes inserted to the required nodes
        temp = head;
        while(temp != NULL){
            if(temp -> random == NULL){
                temp -> next -> random = NULL;
            } else{
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }

        // create the new list
        temp = head;
        Node* newHead = new Node(0);
        Node* newTemp = newHead;

        while(temp != NULL){
            Node* origNext = temp -> next -> next;
            newTemp -> next = temp -> next;
            temp -> next = origNext;
            newTemp = newTemp -> next;
            temp = temp -> next;
        }
        return newHead -> next;
    }
};
