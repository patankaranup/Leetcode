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
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while(n--){
            temp = temp->next;
        }
        if(temp == NULL){
            ListNode* result = head->next;
            delete(head);
            return result;
        }
        ListNode* prev = head;
        while(temp != NULL && temp->next != NULL){
            prev = prev->next;
            temp = temp->next;
        }
        ListNode* deleteNode = prev->next;
        prev->next = deleteNode->next;
        delete(deleteNode);
        return head;
    }
};