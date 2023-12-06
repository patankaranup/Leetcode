class Solution {
public:
    int totalMoney(int n) {
        int amount = 0;
        int mAmt = 1;
        while(n>0){
            int currAmt = mAmt;
            for(int i=1; i<=min(n,7); i++){
                amount += currAmt;
                currAmt++;
            }
            mAmt += 1;
            n -= 7;
        }
        return amount;
    }
};