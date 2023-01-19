#include<bits/stdc++.h>

class Solution {
public:
    int kadanesMax(vector<int>& nums, int n){
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i<n; i++){
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
    int kadanesMin(vector<int>& nums, int n){
        int sum = nums[0];
        int minSum = nums[0];

        for(int i = 1; i<n; i++){
            sum = min(sum+nums[i], nums[i]);
            minSum = min(minSum,sum);
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        // sum of array
        // minSum kadanes algo
        // maxSum kadanes algo for normal array
        // circular max sum for circular array
        int n = nums.size();
        // sum of complete array
        int SUM = accumulate(begin(nums), end(nums),0);

        // minimum summ uisng kadanes algorithm
        int minSum = kadanesMin(nums,n);

        // maximum sum 
        int maxSum = kadanesMax(nums,n);

        // circular sum 
        int circSum = SUM-minSum;

        if (maxSum>0){
            return max(maxSum,circSum);
        }

        return maxSum;
    }
};