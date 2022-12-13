class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSubArr = nums[0]
        currSum = 0
        for n in nums:
            if currSum < 0:
                currSum = 0
            currSum += n
            maxSubArr = max(maxSubArr, currSum)
        return maxSubArr
