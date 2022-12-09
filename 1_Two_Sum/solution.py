class Solution(object):
    def twoSum(self, nums, target):
        prevMap = {}  # val : index
        for index, number in enumerate(nums):  # iter over array
            difference = target - number
            if difference in prevMap:
                return [prevMap[difference], index]
            else:
                prevMap[number] = index

        return
