class Solution1 {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix_N(n+1,0);
        prefix_N[0] = 0;
        vector<int> suffix_Y(n+1,0);
        suffix_Y[n] = 0;

        // fill for N
        for(int i=1; i<=n; i++){
            if(customers[i-1] == 'N'){
                prefix_N[i] = prefix_N[i - 1] + 1;
            } else {
                prefix_N[i] = prefix_N[i - 1];
            }
        }
        // fill for Y
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y'){
                suffix_Y[i] = suffix_Y[i+1] + 1;
            } else {
                suffix_Y[i] = suffix_Y[i+1];
            }
        }

        int minPenalty = INT_MAX;
        int minHour = INT_MAX;

        for(int i=0; i<=n; i++){
            int currPenalty = prefix_N[i] + suffix_Y[i];
            if(currPenalty<minPenalty){
                minPenalty = currPenalty;
                minHour = i;
            }
        }
        return minHour;
    }
};