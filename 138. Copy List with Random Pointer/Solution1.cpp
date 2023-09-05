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

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }

        // Inserting new nodes in betwwen original linked list     
        Node* curr = head;
        
        while(curr) {
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }
        //Deep copy of random pointers
        curr = head;
        while(curr && curr->next) {
            if(curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        //Separating the old and new linked list
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;
        while(curr && newCurr) {
            curr->next = curr->next ? curr->next->next : NULL;
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            curr = curr->next;
            newCurr = newCurr->next;
        }
       
        return newHead;        
    }
};