class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        // O(n*n) TC (10^4)*(10^4) = 10^8 accepted 
        while(i<intervals.size()){
            // ending point of the curr_interval is less than the starting point of new interval then continue 
            if(intervals[i][1] < newInterval[0]){
                i++;
            }else if(intervals[i][0] > newInterval[1]){
                // if the starting point of intervals is greater than the ending point of the interval insert it 
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }else{
                // overlapping interval merge them 
                // start point of new merge interval 
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                // end point of new merge interval 
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};