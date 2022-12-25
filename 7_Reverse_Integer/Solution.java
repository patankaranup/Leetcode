class Solution {
    public int reverse(int x) {
        int res = 0;
        int MIN = -2147483648;
        int MAX = 2147483647;
        while (x!=0){
            int digit = x%10;
            x = x/10;

            if (res > MAX/10 || res == MAX && digit > 7){
                return 0;
            }
            if (res < MIN/10 || res == MIN && digit <8 ){
                return 0;
            }


            res = (res*10)+digit;


        }
        return res;

        
    }
}
