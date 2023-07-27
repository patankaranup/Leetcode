class Solution {
public:
    int computers;
    typedef long long ll;
    bool possible(vector<int>& batteries,ll mid_minutes){
        ll target = computers * mid_minutes;
        ll sum = 0;
        for(int i=0; i<batteries.size(); i++){
            sum += min((ll)batteries[i], (ll)mid_minutes);
            if(sum>=target){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries),end(batteries));
        ll total_minutes = 0;
        computers = n;
        for(auto &minutes : batteries){
            total_minutes += minutes;
        }
        ll r = total_minutes/n;

        ll result = 0;
        while(l<=r){
            ll mid_minutes = l + (r-l)/2;
            if(possible(batteries,mid_minutes)){
                result = mid_minutes;
                l = mid_minutes + 1;
            } else {
                r = mid_minutes - 1;
            }
        }
        return result;

    }
};