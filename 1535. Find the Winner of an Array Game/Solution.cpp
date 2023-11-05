class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxelem = *max_element(begin(arr),end(arr));
        if(k>=n){
            return maxelem;
        }
        int winner = arr[0];
        int wincnt = 0;
        for(int i=1; i<=n; i++){
            if(arr[i]>winner){
                winner = arr[i];
                wincnt = 1;
            }
            else {
                wincnt++;
            }
            if(wincnt == k || winner == maxelem){
                return winner;
            }
        }
        return -1;
    }
};