#include <iostream>
#include <vector>
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
        {
            return;
        }
        int left = 0;
        int right = 0;
        int temp;
        while (right < n)
        {
            if (nums[right] == 0)
            {
                right += 1;
            }
            else
            {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left += 1;
                right += 1;
            }
        }
    }
};
