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
    ListNode* partition(ListNode* head, int x) {
        // make two list node for storing small and large values
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        // make two extra nodes of small and large ptr for traversing 
        ListNode* smallPtr = small;
        ListNode* largePtr = large;
        // iterate over the ll and add the node to small or large based on its value
        while(head){
            if(head->val < x){
                smallPtr->next = head;
                smallPtr = smallPtr->next;
            } else {
                largePtr->next = head;
                largePtr = largePtr->next;
            }
            head = head->next;
        }

        // join both the list 
        smallPtr->next = large->next;
        // point to null in the last node
        largePtr->next = NULL;
        return small->next;
    }
};