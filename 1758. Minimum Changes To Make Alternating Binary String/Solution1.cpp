class Solution1 {
public:
    int minOperations(string s) {
        // to make any binary string char alternative there are only two ways for the string
        // either it will start with 0 i.e. 01010101...
        // or it will start with     1 i.e. 10101010...
        // the start with 0 always has even idx 0 and odd idx 1 in it 
        // the start with 1 always has even idx 1 and odd idx 0 in it 
        int n = s.length();
        int start_with_0 = 0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                // it is even 
                if(s[i] == '1'){
                    start_with_0++;
                } 
            } else {
                if(s[i] == '0'){
                    start_with_0++;
                } 
            }
        }
        return min(start_with_0,n-start_with_0);
    }
};