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
class Solution2 {
public:
    ListNode* curr;
    void solve(ListNode* head){
        if(!head){
            return;
        }
        solve(head->next);

        ListNode* currNext = curr->next;
        if(curr->next == NULL){
            return;
        }else if(head == curr){
            head->next = NULL;
            return;
        }
        curr->next = head;
        head->next = (currNext == head ) ? NULL : currNext;
        curr = currNext;
    }
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};