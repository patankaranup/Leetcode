class Solution {
public:
    int n;
    void solve(int idx, vector<int>& candidates, int target, vector<int> &temp,vector<vector<int>> &result){
        if(idx == n){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        // taking idx 
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            solve(idx,candidates,target-candidates[idx],temp,result);
            // revert it 
            temp.pop_back();
        }
        // skiping idx 
        solve(idx+1,candidates,target,temp,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> result;
        vector<int> temp;
        solve(0,candidates,target,temp,result);
        return result;
    }
};