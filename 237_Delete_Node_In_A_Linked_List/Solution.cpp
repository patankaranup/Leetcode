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
        ListNode* prev = NULL;

        // while node is not empty and next node is not empty
        while(node != NULL && node->next != NULL){
            // assign the next val to the current node
            node->val = node->next->val;
            // save the current node to the prev for pointing the last node to null
            prev = node;
            // base case move forward in the linklist
            node = node->next;
        }
        // make prev node point to null
        prev->next = NULL;
        // delete the last node 
        delete(node);

    }
};
