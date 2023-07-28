class Solution1 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            // how many numbers are misiing current value - actual value
            int missing_nums = arr[mid] - (mid+1);
            if(missing_nums<k){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l+k;
    }
};