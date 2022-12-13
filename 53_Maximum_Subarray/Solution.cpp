#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxsum = INT_MIN;
        for (auto num : nums)
        {
            sum += num;
            maxsum = max(sum, maxsum);
            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};