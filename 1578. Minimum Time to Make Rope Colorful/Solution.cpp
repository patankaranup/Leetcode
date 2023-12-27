class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int time = 0;
        int left = 0;
        for(int right = 1; right<n; right++){
            if(colors[left] == colors[right]){
                if(neededTime[left] < neededTime[right]){
                    time += neededTime[left];
                    left = right;
                } else {
                    time += neededTime[right];
                }
            } else {
                left = right;
            }
        }
        return time;
    }
};