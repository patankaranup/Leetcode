class Solution {
public:
    bool isHappy(int n) {
        // set for having number which has already been calculated
        set<int> my_set;
        // val for the new value after squaring ans summing
        int val;
        // digit for the last digit
        int digit;

        while(1){
            // set initial value to zero
            val = 0;
            // extract the last digit and sqaure and add them to the val
            while(n){
                digit = n%10;
                n /= 10;
                val += digit*digit;
            }
            // if the val is 1 we got the happy number 
            if(val==1){
                return true;
            } 
            // else check whether the number is already present in a set 
if yes there is a loop return false
            else if (my_set.find(val) != my_set.end()){
                return false;
            }
            // otherwise add the number to the set and set the n to the 
new val we calculated
            my_set.insert(val);
            n = val;
        }
        return false;
    }
};
