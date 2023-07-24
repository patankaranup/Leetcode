class Solution {
public:
    double binpow(double a, long b) {
        if(b==0){
            return 1;
        }
        if(b<0){
            return binpow(1/a,-b);
        }
        if(b%2 == 0){
            return binpow(a*a,b/2);
        } else {
            return a * binpow(a*a,(b-1)/2);
        }
    }
    double myPow(double x, int n) {
        return binpow(x,n);
    }
};