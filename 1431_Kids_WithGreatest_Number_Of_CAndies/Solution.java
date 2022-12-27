class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) 
{
        int res = candies[0];
        List<Boolean> output = new ArrayList<>();
        for (int i = 1; i <candies.length;i++){
            if (candies[i]>res){
                res = candies[i];
            }
        }
        for (int i = 0; i <candies.length;i++){
            if (candies[i]+extraCandies < res){
                output.add(false);
            }
            else {
                output.add(true);
            }
        }
        return output;
    }
}
