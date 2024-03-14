class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int result  = 0;
        int prefSum = 0;
        // prefSum of 0 is 1 
        mp[0] = 1; 
        for(int &num : nums){
            prefSum += num; 
            int remaining_sum = prefSum - goal;
            if(mp.find(remaining_sum) != mp.end()){
                result += mp[remaining_sum];
            }
            mp[prefSum]++;
        }
        return result;
    }
};