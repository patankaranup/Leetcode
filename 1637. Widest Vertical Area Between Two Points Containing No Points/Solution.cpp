class Solution {
public:
    typedef long long ll;
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int n = points.size();
        ll res = 0; 
        for(int i=1; i<n; i++){
            ll diff = points[i][0] - points[i-1][0];
            res = max(res,diff);
        }
        return res;
    }
};