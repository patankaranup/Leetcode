class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // add total gas availabe and total cost if totalgas is less than total 
cost return -1
        int totalGas = accumulate(begin(gas),end(gas),0);
        int totalCost = accumulate(begin(cost),end(cost),0);
        if (totalGas < totalCost){
            return -1;
        }
        // run for loop over all index greedily 
        int result_index = 0; // starting index
        int total =  0; // total gas at starting index
        for (int i = 0; i<n; i++){
            // add total gas which is available to travel gas at i position and 
subtract cost at i position
            total += gas[i] - cost[i];
            if (total<0){
                // if total is less than 0 than we canno travel to next position 
update the index 
                result_index = i+1;
                total = 0;
            }
        }
        return result_index;
    }
};
