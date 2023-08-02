class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;
    int n;
    void solvePermutations(vector<int>& nums,vector<int> &temp){
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(st.find(nums[i]) == st.end()){
                // take i and explore further 
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                // explore further permutations
                solvePermutations(nums,temp);
                // reject i and explore 
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solvePermutations(nums,temp);
        return result;
    }
};