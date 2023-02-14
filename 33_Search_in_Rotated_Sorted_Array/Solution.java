class Solution {
    public int search(int[] nums, int target) {
        int pivot = findPivot(nums);
        // no pivot present that means array not rotated normal binary search 
        if(pivot == -1){
            return binarySearch(nums, 0, nums.length-1, target);
        } 
        // if pivot found we have two ascending arrays
        if(nums[pivot] == target){
            return pivot;
        } else if (target>=nums[0]){
            return binarySearch(nums, 0, pivot-1, target);
        } else {
            return binarySearch(nums, pivot+1, nums.length-1, target);
        }
    }

    int findPivot(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        // array not rotated
        if (nums[start] <= nums[end]) {
            return -1;
        }
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(mid < end && nums[mid] > nums[mid+1]){
                return mid;
            } else if(mid > start && nums[mid] < nums[mid-1]){
                return mid-1;
            } else if(nums[mid] <= nums[start]){
                end = mid-1;
            } else{
                start = mid+1;
            }
        }
        return -1;
    }

    int binarySearch(int[] nums, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                start = mid + 1;
            } else{
                end = mid - 1;
            }
        }
        return -1;
    }
}

