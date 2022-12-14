class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int 
additionalRocks) {
        int n  = capacity.size();
        for (int i = 0; i <n ; i++ ){
            capacity[i] = capacity[i] - rocks[i];
        }
        sort(capacity.begin(),capacity.end());

        int count = 0;
        for (int i = 0; i < n ; i++){
            if (capacity[i] == 0){
                count +=1;
            } else if (capacity[i]<= additionalRocks){
                count++;
                additionalRocks = additionalRocks-capacity[i];
            } else {
                break;
            }
        }
        return count;
        
    }
};

