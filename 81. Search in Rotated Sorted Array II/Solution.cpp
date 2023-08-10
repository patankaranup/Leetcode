class Solution {
public:
    int n;
    int findPivot(vector<int>& nums){
        int l = 0;
        int r = n-1;

        // normal binary search just add few lines to skip duplicates
        while(l<r){
            // skip duplicates from left and right 
            while(l<r && nums[l] == nums[l+1]){
                l++;
            }
            while(r>l && nums[r] == nums[r-1]){
                r--;
            }
            // binary search
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            } 
            if(nums[mid]<nums[r]){
                r = mid;
            }
        }
        return r;
    }
    bool binarySearch(vector<int>& nums, int &target,int start, int end){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return true;
            } else if(nums[mid]>target){
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        n = nums.size();
        int pivot = findPivot(nums);
        if(binarySearch(nums,target,0,pivot-1)){
            return true;
        } else if(binarySearch(nums,target,pivot,n-1)){
            return true;
        } else {
            return false;
        }
    }
};