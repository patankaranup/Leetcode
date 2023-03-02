class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int slow = nums[0];
        int fast = nums[0];
        // floyds cycle detection
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        // finding the repeating number
        fast = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;

    }
};
