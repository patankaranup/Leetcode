class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;
        // Find longest common prefix in both numbers in binary 
        // this are the bits that will be the same for both and other will become 0 
        while(left != right){
            left = left >> 1;
            right = right >> 1;
            shiftCount++;
        }
        return (left << shiftCount);
    }
};