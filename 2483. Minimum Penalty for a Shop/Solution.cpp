class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int minPenalty = INT_MAX;
        int minHour = INT_MAX;

        for(int i=0; i<n; i++){
            // if shop is open but no customers come
            int j = i-1; 
            int open_penalty = 0;
            while(j>=0){
                if(customers[j] == 'N'){
                    open_penalty++;
                }
                j--; 
            }
            // if shop is closed but customer come
            j = i;
            int closed_penalty = 0;
            while(j<n){
                if(customers[j] == 'Y'){
                    closed_penalty++;
                }
                j++;
            }
            int curr_penalty = open_penalty + closed_penalty;
            if(curr_penalty<minPenalty){
                minPenalty = curr_penalty;
                minHour = i;
            }
        }
        // closing at nth hour that is shop was open for all time
        // 0 to n-1
        int nthHourPeanlty = count(begin(customers),end(customers),'N');
        if(nthHourPeanlty < minPenalty){
            minPenalty = nthHourPeanlty;
            minHour = n;
        }
        return minHour;
        
    }
};