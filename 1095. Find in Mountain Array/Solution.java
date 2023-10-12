/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int start = 0, end = n - 1;
        int peak = 0;
        
        // find the peak element
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            } else {
                peak = mid;
                end = mid - 1;
            }
        }
        // binary search on the left side of the peak element
        int left = binarySearch(mountainArr, 0, peak, target, true);
        if (left != -1) return left;
        
        // binary search on the right side of the peak element
        int right = binarySearch(mountainArr, peak, n - 1, target, false);
        return right;
    }
    
    public int binarySearch(MountainArray mountainArr, int start, int end, int target, boolean isAsc) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) return mid;
            else if (midVal < target) {
                if (isAsc) start = mid + 1;
                else end = mid - 1;
            } else {
                if (isAsc) end = mid - 1;
                else start = mid + 1;
            }
        }
        return -1;
    }
}