class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int minS = *min_element(begin(salary),end(salary));
        int maxS = *max_element(begin(salary),end(salary));
        int sum = accumulate(begin(salary),end(salary), 0);

        return (double)(sum - maxS - minS)/(double)(n-2);
    }
};