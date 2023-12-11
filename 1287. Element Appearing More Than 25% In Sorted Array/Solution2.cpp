class Solution2 {
public:
    int firstPos(int num, int start, int end, vector<int>& arr){
        int pos = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == num) {
                pos = mid;
                end = mid-1;
            } else if(arr[mid]<num) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return pos;
    }
    int lastPos(int num, int start, int end, vector<int>& arr){
        int pos = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == num) {
                pos = mid;
                start = mid+1;
            } else if(arr[mid]<num) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return pos;
    }
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;
        // 25th percent 50 percent and 75th percent
        vector<int> numbers{arr[n/4], arr[n/2], arr[3*n/4]};
        for(int &number : numbers) {
            int f = firstPos(number, 0, n-1, arr);
            int l = lastPos(number, 0, n-1, arr);
            if(l-f+1 > freq) {
                return number;
            }
        }
        return -1;
    }
};