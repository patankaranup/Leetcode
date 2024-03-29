class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int> start_time(m);
        vector<int> end_time(m);
        vector<int> result(n);

        for(int i=0; i<m; i++){
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        sort(begin(start_time),end(start_time));
        sort(begin(end_time),end(end_time));

        for(int i=0;i<n; i++){
            int time = people[i];
            int already_bloomed = upper_bound(begin(start_time),end(start_time), time) - begin(start_time);
            int already_died = lower_bound(begin(end_time),end(end_time), time) - begin(end_time);

            result[i] = already_bloomed - already_died;
        }
        return result;
    }
};