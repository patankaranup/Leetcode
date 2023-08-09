class Solution {
public:
    int n;
    bool isValid(int mid,vector<int>& nums, int &p){
        int i = 0;
        int count_pairs = 0;
        while(i<n-1){
            int first_val = nums[i];
            int second_val = nums[i+1];
            int diff = (second_val-first_val);
            if(diff<=mid){
                count_pairs +=1;
                i += 2; 
            } else {
                i++;
            }   
        }
        return count_pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums),end(nums));
        int l = 0;
        int r = nums[n-1]-nums[0];

        int result = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(mid,nums,p)){
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return result;
    }
};