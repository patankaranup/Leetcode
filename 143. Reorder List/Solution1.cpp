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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        int k = st.size()/2;
        curr = head;
        while(k--){
            ListNode* top = st.top();
            st.pop();

            ListNode* currNext = curr->next;
            curr->next = top;
            top->next = currNext;
            curr = currNext;
        }
        // curr will be pointing to last node (itself) and will create cycle 
        curr->next = NULL;
    }
};