class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majElem = NULL;

        for(int i=0; i<n; i++){
            if(count == 0){
                count = 1;
                majElem = nums[i];
            } else if(nums[i] == majElem){
                count++;
            } else {
                count--;
            }
        }
        return majElem;
    }
};