class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> time_remaining(n);

        for(int i=0; i<n; i++){
            time_remaining[i] = ceil( (float) dist[i] / speed[i] );
        }
        sort(begin(time_remaining),end(time_remaining));
        int count = 1;
        int time_passed = 1;
        
        for(int i=1; i<n; i++){
            if(time_remaining[i] - time_passed <= 0){
                return count;
            }
            time_passed++;
            count++;
        }
        return count;
    }
};