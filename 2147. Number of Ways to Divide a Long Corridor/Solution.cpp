class Solution {
public:
    int MOD = 1e9+7;
    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<int> seatsIdx;

        for(int i=0; i<n; i++){
            if(corridor[i] == 'S'){
                seatsIdx.push_back(i);
            }
        }

        int noOfS = seatsIdx.size();
        if( noOfS % 2 != 0 || noOfS == 0){
            return 0;
        }

        long long result = 1;
        int prevSidx = seatsIdx[1];

        for(int i=2; i<noOfS; i+=2){
            int diffIdx = seatsIdx[i]-prevSidx;
            result = (result * diffIdx)%MOD;
            prevSidx = seatsIdx[i+1];
        }
        return result;
    }
};