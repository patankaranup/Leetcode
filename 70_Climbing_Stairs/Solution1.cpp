class Solution1 {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3){
            return n;
        }

        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i=3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};