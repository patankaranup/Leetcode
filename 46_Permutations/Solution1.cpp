class Solution1 {
public:
    vector<vector<int>> result;
    int n;
    void solvePermutations(int idx,vector<int>& nums){
        if(idx==n){
            result.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            // do 
            swap(nums[i],nums[idx]);
            // explore 
            solvePermutations(idx+1,nums);
            // undo 
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solvePermutations(0,nums);
        return result;
    }
};