class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int firstMax = 0;
        int secondMAx = 0;
        for(int i=0; i<n; i++){
            int curr = nums[i];
            if(curr>firstMax){
                secondMAx = firstMax;
                firstMax = curr;
            } else if(curr>secondMAx){
                secondMAx = curr;
            }
        }
        return (firstMax - 1)*(secondMAx - 1);
    }
};