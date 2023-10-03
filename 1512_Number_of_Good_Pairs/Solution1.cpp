class Solution1 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result = 0;
        for(int &num : nums){
            mp[num]++;
        }
        for(auto &it : mp){
            int count = it.second;
            result += (count * (count-1))/2;
        }
        return result;
    }
};