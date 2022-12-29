class Solution {
    public int[] searchRange(int[] nums, int target) {
        

        int[] ans = {-1,-1};
        int start = search(nums,target,true);
        int end = search(nums, target, false);
        ans[0] = start;
        ans[1] = end; 
        return ans;

    }
    int search(int[] nums, int target, boolean search_for_left){
        int left = 0;
        int right = nums.length-1;
        int index = -1;
        while (left <= right){
            int mid = left+(right-left)/2;
            if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid]<target){
                left = mid+1;
            } else {
                index = mid;
                if (search_for_left){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return index;
    }
}
