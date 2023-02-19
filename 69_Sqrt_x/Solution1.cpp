class Solution1 {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = INT_MAX;
        int ans = 0;
        while(start<=end){
            long long m = start +(end- start)/2;
            if(m*m<=x){
                ans = m;
                start = m+1;
            } else {
                end = m-1;
            }
        }
        return ans;
    }
};
