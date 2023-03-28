class Solution {
public:
    int t[366];
    int recursion(vector<int>& days, vector<int>& costs, int n, int i){
        if(i>=n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        // 1 day pass costs
        int cost_1 = costs[0] + recursion(days,costs,n,i+1);

        // 7 days pass costs
        int j = i;
        int max_days = days[i]+7;
        while(j<n && days[j] < max_days){
            j++; 
        }
        int cost_7 = costs[1] + recursion(days,costs,n,j);

        // 30 days pass costs
        j = i;
        max_days = days[i]+30;
        while(j<n && days[j] < max_days){
            j++; 
        }
        int cost_30 = costs[2] + recursion(days,costs,n,j);

        return t[i] = min({cost_1,cost_7,cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t,-1,sizeof(t));
        return recursion(days,costs,n,0);
    }
};
