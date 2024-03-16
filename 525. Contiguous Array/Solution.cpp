class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int curr_sum = 0;
        int max_len  = 0;
        // cumsum to index (Same like two sum)
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            curr_sum += (nums[i] == 1) ? 1 : -1;
            // previosuly we see this sum and now again we get the same sum 
            // that means we add subtract something that again lead us to 0
            if(mp.find(curr_sum) != mp.end()){
                int last_idx = mp[curr_sum];
                max_len = max(max_len,i-last_idx);
            }else{
                // this condition is in else beacause we dont want to update the previos idx 
                mp[curr_sum] = i;
            }
        }
        return max_len;
    }
};