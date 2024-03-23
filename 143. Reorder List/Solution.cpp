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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* last = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverseLinkedList(slow);
        ListNode* curr = head;
        while(tail->next != NULL){
            ListNode* currNext = curr->next;
            ListNode* tailNext = tail->next;

            curr->next = tail;
            tail->next = currNext;

            curr = currNext;
            tail = tailNext;
        }
    }
};