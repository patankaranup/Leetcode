/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIdx(MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        
        return l;
    }
    int binSear(MountainArray &mountainArr, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }   
        return -1;
    }

    int revBinSear(MountainArray &mountainArr, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) { 
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = peakIdx(mountainArr);
        int idx = binSear(mountainArr, 0, peakIndex, target);
        if(idx == -1) {
            return revBinSear(mountainArr, peakIndex, n-1, target);
        }
        return idx;
    }
};