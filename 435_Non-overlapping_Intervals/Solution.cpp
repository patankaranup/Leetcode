class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n = intervals.size();
        int deleteCount = 0;
        int i = 1;
        vector<int> L = intervals[0];

        while(i<n){
            
            int curr_end = intervals[i][1];
            int curr_start = intervals[i][0];

            int last_end = L[1];
            int last_start = L[0];

            if(curr_start>=last_end){
                L = intervals[i];

            } else if(curr_end >= last_end){
                deleteCount++;

            } else if(curr_end < last_end){
                deleteCount++;
                L = intervals[i];

            }
            i++;
        }
        return deleteCount++;
    }
};