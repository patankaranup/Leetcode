class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        for(int &num : nums){
            mp[num]++;
        }
        for(auto &iter : mp){
            int freq = iter.second;
            if(freq == 1){
                return -1;
            }
            res += (ceil((double)freq/3));
        }
        return res;
    }
};