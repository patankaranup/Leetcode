class Solution {
    public int maximumWealth(int[][] accounts) {
        
        int max_res = Integer.MIN_VALUE;

        for (int i = 0; i < accounts.length; i++){
            int sum = 0;
            for (int j = 0; j < accounts[i].length; j++){
                sum += accounts[i][j];
            }
            max_res = Math.max(sum,max_res);
        }
        return max_res;
    }
}
