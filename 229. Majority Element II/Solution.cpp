class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int majElem1 = NULL;
        int count2 = 0;
        int majElem2 = NULL;

        for(int i=0; i<n; i++){
            if(nums[i] == majElem1){
                count1++;
            } else if(nums[i] == majElem2){
                count2++;
            } else if(count1 == 0){
                majElem1 = nums[i];
                count1 = 1;
            } else if(count2 == 0){
                majElem2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;
        for(int &num : nums){
            if(num == majElem1){
                freq1++;
            } else if(num == majElem2){
                freq2++;
            }
        }
        if(freq1>floor(n/3)){
            result.push_back(majElem1);
        }if(freq2>floor(n/3)){
            result.push_back(majElem2);
        }
        return result;
    }
};