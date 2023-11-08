class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int hor_dist = abs(sx-fx);
        int ver_dist = abs(sy-fy);
        if(hor_dist == 0 && ver_dist == 0 && t == 1){
            return false;
        }
        int min_time = max(hor_dist,ver_dist);
        if(t<min_time){
            return false;
        }
        return true;
    }
};