class Solution1 {
public:
    bool exists(vector<int>& nums, int num){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == num){
                return true;
            } else if(nums[mid] < num){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        unordered_set<int> st;
        for(auto &num : nums2){
            if(exists(nums1,num)){
                st.insert(num);
            }
        }
        vector<int> res(begin(st),end(st));
        return res;
    }
};