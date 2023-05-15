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
    int findLength(ListNode* head){
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        // kth node from start 
        // ktn node from end (that is len(ll) - k + 1)
        int L = findLength(head);
        int k_1 = k;
        ListNode* node1 = head;
        while(k_1 > 1){
            node1 = node1 -> next;
            k_1--;
        }
        int k_2 = L - k + 1;
        ListNode* node2 = head;
        while(k_2 > 1){
            node2 = node2 -> next;
            k_2--;
        }
        swap(node1->val,node2->val);
        return head;
    }
};

