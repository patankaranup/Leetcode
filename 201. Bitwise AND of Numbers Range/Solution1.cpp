class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // n & (n-1) clears the rightmost set bit 
        while(right>left){
            right = right & (right - 1);
        }
        return right;
    }
}; 