class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        
        # Finding the candidate
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        
        # Verifying if the candidate is the majority element
        count = 0
        for num in nums:
            if num == candidate:
                count += 1
        
        # If the candidate is the majority element, return it
        if count > len(nums) // 2:
            return candidate
        else:
            return -1 