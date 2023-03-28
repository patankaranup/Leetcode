class Solution1 {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days),end(days));
        int last_day = days.back();
        vector<int> t(last_day+1,0); // minimu cost totravel till day i
        t[0] = 0;

        for(int i=1; i<=last_day; i++){
            // check if you have to travel on ith day or not
            if(st.find(i) == st.end()){
                t[i] = t[i-1];
                continue;
            }
            t[i] = INT_MAX;
            int passOf1Day = costs[0] + t[max(i-1,0)];
            int passOf7Day = costs[1] + t[max(i-7,0)];
            int passOf30Day = costs[2] + t[max(i-30,0)];

            t[i] = min({passOf1Day,passOf7Day,passOf30Day});
        }

        return t[last_day];
    }
};
