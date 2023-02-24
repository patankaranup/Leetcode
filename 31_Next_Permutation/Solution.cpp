class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // if size of 1 array return 
        if(n==1){
            return;
        }
        // start from index 1
        int i=1;
        int peakIndex = -1; // set peak index to -1
        // loop over and update the last peak index 
        while(i<n){
            if(nums[i]>nums[i-1]){
                peakIndex = i;
            }
            i++;
        }
        // if peak index not found then array is descending 
        if(peakIndex==-1){
            // swap the array and return
            for(int i = 0; i<n/2; i++){
                swap(nums[i], nums[n-i-1]);
            }
            return;
        }
        // now we have to swap the last index with the previous one or the 
element which is greater than the previous index which is present on the 
right half of the peak index
        int indexToSwap = peakIndex;

        for(int i = peakIndex;i<n; i++){
            // check whether the index at i is greater than index previous 
to peak and also the index should be less than current indexToSwap
            if(nums[i]>nums[peakIndex-1] && nums[i]<nums[indexToSwap]){
                indexToSwap = i;
            }

        }
        swap(nums[peakIndex-1], nums[indexToSwap]);
        // and then sort the remaing array from the peak index
        sort(nums.begin()+peakIndex,nums.end());
    }
};
