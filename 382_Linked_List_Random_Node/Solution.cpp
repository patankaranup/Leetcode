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
    vector<int> vec;
    Solution(ListNode* head) {
        ListNode* root = head;
        while(root){
            int val = root->val;
            vec.push_back(val);
            root = root->next;
        }
    }
    
    int getRandom() {
        int n = vec.size();

        int randIdx = rand()%n;
        
        return vec[randIdx];

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */