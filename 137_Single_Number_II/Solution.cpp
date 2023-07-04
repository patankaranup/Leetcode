class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int kth_bit = 0; kth_bit<=31; kth_bit++ ){
            int temp = (1<<kth_bit);
            int zero_count = 0;
            int one_count = 0;
            for(int &num : nums){
                if((num&temp) == 0){
                    zero_count++;
                } else{
                    one_count++;
                }
            }
            if(one_count%3 == 1){
                result = (result|temp);
            }
        }
        return result;
    }
};
