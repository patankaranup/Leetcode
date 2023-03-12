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
    ListNode* mergetTwoSortedLists(ListNode* l1, ListNode* l2){
        // if l1 or l2 is null return the alternate list
        if(!l1) return l2;
        if(!l2) return l1;
        // using recursion to merge two sorted lists 
        if(l1->val <= l2->val){
            l1->next = mergetTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergetTwoSortedLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& 
lists){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        } 
        int mid = start +(end-start)/2;
        ListNode* L1 = partitionAndMerge(start,mid,lists);
        ListNode* L2 = partitionAndMerge(mid+1,end,lists);
        return mergetTwoSortedLists(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // intution 
        // write a helper function to merge two lists
        // apply merge sort to the vector and merge the linked list
        // if only one list is present return it
        // if two are present merge them
        int k = lists.size();
        if(k==0){
            return NULL;
        }
        return partitionAndMerge(0, k-1, lists);
    }
};
