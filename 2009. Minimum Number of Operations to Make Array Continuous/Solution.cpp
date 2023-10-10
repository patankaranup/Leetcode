class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st(begin(nums),end(nums));
        vector<int> temp(begin(st),end(st));
        int min_ops = INT_MAX;

        for(int i=0; i<temp.size(); i++){
            int curr_min = temp[i];
            int curr_max = curr_min+n-1;
            int j = upper_bound(begin(temp),end(temp),curr_max) - begin(temp);
            int within_range = j-i;
            int out_of_range = n - within_range;
            min_ops = min(min_ops,out_of_range);
        }
        return min_ops;
    }
};