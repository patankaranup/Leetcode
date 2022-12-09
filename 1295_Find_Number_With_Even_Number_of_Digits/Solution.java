class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int n : nums) {
            if (String.valueOf(n).length() % 2 == 0) { // this is to parse int to string to use the length ffunction
                count += 1;
            }
        }

        return count;

    }
}