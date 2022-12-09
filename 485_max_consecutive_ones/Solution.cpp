#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, maximum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count = count + 1;
            }
            else
            {
                count = 0;
            }
            maximum = max(maximum, count);
        }
        return maximum;
    }
};