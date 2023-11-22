class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> result;
        unordered_map<int,vector<int>> mp;
        for(int row = nums.size()-1; row>=0; row--){
            for(int col = 0; col<nums[row].size(); col++){
                mp[row+col].push_back(nums[row][col]);
            }
        }
        int diagnol = 0;
        while(mp.find(diagnol) != mp.end()){
            for(auto &num : mp[diagnol]){
                result.push_back(num);
            }
            diagnol++;
        }
        return result;
    }
};