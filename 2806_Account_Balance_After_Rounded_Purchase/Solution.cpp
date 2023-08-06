class Solution {
public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    if(purchaseAmount == 0){
        return 100;
    }
    int quotient = purchaseAmount/10;
    int remainder = purchaseAmount%10;
    if(remainder>=5){
        quotient = quotient*10+10;
    }else {
      quotient=quotient*10;
    }
    return 100 - quotient;
  }
};