class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result = 0;
        for(int &num : nums){
            result += mp[num];
            mp[num]++;
        }
        return result;
    }
};