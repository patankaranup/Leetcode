class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int > mp;
        int sum = 0;

        mp[0] = 1;
        int result = 0;

        for(int i = 0; i<n; i++){
            sum+=nums[i];
            int remainder = sum%k;
            if (remainder<0){
                remainder+=k;
            }
            if (mp.find(remainder) != mp.end()){
                result += mp[remainder];
            } 
            mp[remainder]++;
             
        }

        return result;
    }
};