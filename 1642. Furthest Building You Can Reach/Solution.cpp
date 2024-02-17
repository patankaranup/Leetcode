class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i = 0;
        priority_queue<int> pq;
        for(; i<n-1; i++){
            if(heights[i+1]<=heights[i]){
                continue;
            }
            int diff = heights[i+1] - heights[i];
            if(diff <= bricks){
                bricks -= diff;
                pq.push(diff);
            } else if(ladders>0){
                if(!pq.empty()){
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff) {
                        // get the last max brikcs which we used last time and use a ladder instead of bricks 
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
};