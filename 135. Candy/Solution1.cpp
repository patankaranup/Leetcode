class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = n; //Each person given one candy
        
        int i = 1;
        while(i < n){
            // if same rating continue to next one 
            if(ratings[i]==ratings[i-1]) {
                i++;
                continue;
            }
            //if increasing Slope is there 
            int peakVal = 0;
            while(ratings[i] > ratings [i-1]){
                peakVal++;
                result += peakVal;
                i++;
                if(i == n) {
                    return result;
                }
            }
            // if decreasing slope 
            int valleyVal = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valleyVal++;
                result += valleyVal;
                i++;
            }
            // we have added both peak and vall to result but we only need the maximum one so we delete the minumm from result 
            result -= min(peakVal, valleyVal);
        }
        
        return result;
    }
};