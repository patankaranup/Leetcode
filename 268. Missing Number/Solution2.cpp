class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int ans = n;
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] > mid){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};