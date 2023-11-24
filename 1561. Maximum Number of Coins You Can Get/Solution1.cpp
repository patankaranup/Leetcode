class Solution1 {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles),end(piles));
        int numOfTilesForEach = n/3;
        int coins = 0;
        for(int myTile=numOfTilesForEach; myTile<n; myTile+=2){
            coins += piles[myTile];
        }
        return coins;
    }
};