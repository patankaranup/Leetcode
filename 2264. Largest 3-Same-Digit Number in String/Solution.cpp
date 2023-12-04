class Solution {
public:
    string largestGoodInteger(string nums) {
        char maxChar = ' ';
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1]&&nums[i]==nums[i-2]){
                maxChar = max(nums[i],maxChar);
            }
        }
        if(maxChar == ' '){
            return "";
        }
        return string(3,maxChar);
    }
};