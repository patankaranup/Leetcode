class Solution2 {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }

        int a = 1; // i-2
        int b = 2; // i-1
        int c = 3; // i

        for(int i=3; i<=n; i++){
            c = a + b;
            int temp_b = b;
            b = c;
            a = temp_b;
        }

        return c;
    }
};