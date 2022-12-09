#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (auto const num : nums)
        {
            if (((int(log10(num) + 1)) % 2) == 0) // use logarithmic finction to get number of digits and then do modulo operation
            {
                count++;
            }
        }
        return count;
    }
};