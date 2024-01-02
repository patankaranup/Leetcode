class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);
        vector<vector<int>> result;
        for(int i=0; i<n; i++){
            int f = freq[nums[i]];
            // found new duplicate time to push in next row 
            if(f == result.size()){
                result.push_back({});
            }
            result[f].push_back(nums[i]);
            freq[nums[i]]++;
        }
        return result;
    }
};