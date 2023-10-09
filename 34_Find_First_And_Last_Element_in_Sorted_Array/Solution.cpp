class Solution {
public:
    int findLeftMost(vector<int>& nums, int target, int n){
        int l = 0, r = n-1;
        int l_idx = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target){
                l_idx = mid;
                r = mid-1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l_idx;
    }
    int findRightMost(vector<int>& nums, int target, int n){
        int l = 0, r = n-1;
        int r_idx = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target){
                r_idx = mid;
                l = mid+1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return r_idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findLeftMost(nums,target,n);
        int right_most = findRightMost(nums,target,n);

        return {left_most,right_most};
    }
};