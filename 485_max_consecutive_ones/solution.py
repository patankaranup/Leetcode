class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0  # for number of consecutive ones count
        maximum = 0  # maximum number of counts found
        for i in range(len(nums)):
            if nums[i] == 1:  # if num is 1 update the count to 1

                count += 1

                # update the maximum number to max of count or previous max
                maximum = max(count, maximum)
            else:

                count = 0  # if count is not 1 it is 0 so reset the count to 0
        return maximum
