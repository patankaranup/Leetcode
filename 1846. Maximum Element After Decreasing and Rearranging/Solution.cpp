class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        int maxElem = 1;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                arr[i] = 1;
            } else if(arr[i] - arr[i-1] > 1) {
                arr[i] = arr[i-1] + 1;
            }
            maxElem = max(maxElem, arr[i]);
        }
        return maxElem;
    }
};