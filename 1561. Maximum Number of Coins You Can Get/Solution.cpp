class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles),end(piles));
        int bob = 0;
        int me = n-2;
        int alice = n-1;
        int coins = 0;
        while(bob<me){
            coins += piles[me];
            me -= 2;
            bob += 1;
        }
        return coins;
    }
};