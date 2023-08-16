class Solution {
public:
    // 1 When new elements come make space for it window size cant be greater than k
    // 2 when new element comes remove the small element from the window pop them
    // 3 Now push i in deque 
    // 4 if i>=k-1 then deq.front() is our answer for that window 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;
        for(int i=0; i<n; i++){
            // make space for nums[i]
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            // remove small elements
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i>=k-1){
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};