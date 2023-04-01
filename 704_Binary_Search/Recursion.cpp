class Recursion {
public:
    int binarySearch(int l, int r,vector<int>& nums,int target){
        if(l>r){
            return -1;
        }
        int mid = l + (r-l)/2;
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid]>target){
            return binarySearch(l,mid-1,nums,target);
        } else{
            return binarySearch(mid+1,r,nums,target);
        } 
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0){
            return -1;
        } 
        return binarySearch(0,n-1,nums,target);
    }
};