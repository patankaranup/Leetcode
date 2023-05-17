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
    int pairSum(ListNode* head) {
        // find mid node 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        // reverse next half of the linked list
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        
        while(mid != NULL){
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;          
        }
        // add the node and update the result 
        int result = 0;
        ListNode* curr = head;
        while(prev != NULL){
            result = max(result, prev->val + curr->val);
            curr = curr->next;
            prev = prev->next;
        }
        return result;


    }
};