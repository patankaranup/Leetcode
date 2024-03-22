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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode*temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // check for odd or even len of linked list 
        if(fast){
            // odd elements 
            slow = slow->next;
        }
        while(prev && slow){
            if(prev->val != slow->val){
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};