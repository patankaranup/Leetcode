class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # this is two pinter approach
        result = []
        l = 0
        r = len(nums)-1
        while l <= r:
            if nums[l]**2 < nums[r]**2:
                result.append(nums[r]**2)
                r -= 1
            else:
                result.append(nums[l]**2)
                l += 1
        return result[::-1]  # returns result in negative order
