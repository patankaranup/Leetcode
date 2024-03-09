class Solution1 {
public:
    bool exists(int num, vector<int>& nums2){
        int l = 0;
        int r = nums2.size() - 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums2[mid] == num){
                return true;
            }else if(nums2[mid]<num){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int &num : nums1){
            if(exists(num,nums2)){
                return num;
            }
        }
        return -1;
    }
};