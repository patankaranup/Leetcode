class Solution1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int window_sum = 0;
        int count = 0;
        int zero_cnt = 0;
        while(j<n){
            window_sum += nums[j];
            while(i<j && (window_sum > goal || nums[i] == 0)){
                if(nums[i] == 0){
                    zero_cnt++;
                }else{
                    zero_cnt = 0;
                }
                window_sum -= nums[i];
                i++; 
            }
            if(window_sum == goal){
                count = count + 1 + zero_cnt;
            }
            j++;
        }
        return count;
    }
};