class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // size of array
        int n = points.size();
        // we need to sort based on the starting points
        sort(begin(points), end(points));
        // previous points
        vector<int> prev = points[0];
        // number of arrows
        int count = 1;
        for (int i = 1; i<n;i++){
            // current points
            int curSp = points[i][0];
            int curEp = points[i][1];
            // previous points
            int prevSp = prev[0];
            int prevEp = prev[1];
            // no overlap
            if (curSp>prevEp){
                count+=1;
                prev = points[i];
            } else {
                // overlap 
                // check forfurther overlaps by changing prevsp and curep
                // overlaping region
                prev[0] = max(prevSp,curSp);
                prev[1] = min(prevEp, curEp);
            }

        }
        return count;
        
    }
};