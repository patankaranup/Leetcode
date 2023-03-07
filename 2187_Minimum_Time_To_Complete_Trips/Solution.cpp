class Solution {
public:
    bool canBeCompleted(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTrips =  0;
        for (int &t:time){
            actualTrips += givenTime/t; // number of trips for every bus
        }
        return actualTrips>=totalTrips; 
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // starting time 1 second and ending max time is time taken by the 1st bus multiply by totalTrips
        int n = time.size();
        long long l = 1;
        long long r = (long long) *min_element(begin(time),end(time)) * totalTrips;
        // search in middle of the time for the optimize time to complete totaltrips
        while(l<r){
            long long mid = l+(r-l)/2;
            
            if(canBeCompleted(time,mid,totalTrips)){
                r = mid;
            } else {
                l = mid+1;
            }
            
            
        }
        return l;
    }
};
