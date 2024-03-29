class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;

        while(l<r){
            int mid = l + (r-l)/2;

            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }else if(arr[mid]>arr[mid+1]){
                r = mid;
            }
        }
        return r;
    }
};