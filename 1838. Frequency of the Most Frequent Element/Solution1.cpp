class Solution1 {
public:
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int result = 0;
        int l = 0;
        ll currSum = 0;
        for(int r=0; r<n; r++){
            ll target = nums[r];
            currSum += nums[r];
            int originalSum = (r-l+1)*target;
            int ops = originalSum - currSum;
            if(ops>k){
                // shrinking window 
                currSum -= nums[l];
                l++;
            }
            result = max(result,(r-l+1));
        }
        return result;
    }
};