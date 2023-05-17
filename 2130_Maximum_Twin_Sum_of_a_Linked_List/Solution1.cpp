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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr!=NULL){
            st.push(curr->val);
            curr = curr->next;
        }
        int n = st.size();
        curr = head;
        int count = 1;
        int result = 0;
        while(count <= n/2){
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop(); 
            count++;
        }
        return result;
    }
};