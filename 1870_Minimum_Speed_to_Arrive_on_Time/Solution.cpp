class Solution {
public:
    double h;
    int n;
    double timeToTravel(vector<int>& dist, double speed){
        double time = 0.0;
        int i = 0;
        for(; i<n-1; i++){
            double t = (double)dist[i]/(double)speed;
            time += ceil(t);
            if(time>h){
                return time;
            }
        }
        time += dist[i]/speed;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        h = hour;
        n = dist.size();
        int l = 1;
        int r = 1e7;
        int result = -1;
        while(l <= r){
            int mid_speed = l + (r - l)/2;
            if(timeToTravel(dist,mid_speed) <= hour){
                result = mid_speed;
                r = mid_speed - 1;
            } else {
                l = mid_speed + 1;
            }
        }
        return result;
    }
};