class Solution2 {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        int minHour = 0;
        int penalty = count(begin(customers),end(customers),'Y');
        int minPenalty = penalty;
        
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                penalty--;
            } else {
                penalty++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHour = i+1;
            }
        }
        return minHour;
    }
};