class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =0;
        int high =nums.size() -2;

        while(low<=high){
            int mid = low + (high - low)/2;
            // we can use xor if the number is odd it will give the previos even and if it is even number it will give 
the next odd 
            if(nums[mid] == nums[mid^1]){
                // if it is same search in the right half
                low = mid + 1;
            } else {
                high = mid-1;
            }
        }
        return nums[low];
    }
};
