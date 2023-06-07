class Solution1 {
public:
    int minFlips(int a, int b, int c) {
        int result = ((a|b) ^ c);
        // for both bits 1 in a & b
        int result_1 = a & b;

        int result_2 = (result_1 & result);

        return __builtin_popcount(result) + __builtin_popcount(result_2);
    }
};
