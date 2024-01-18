class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1 or n == 2:
            return n

        a = 1  # i-2
        b = 2  # i-1
        c = 3  # i

        for i in range(3, n + 1):
            c = a + b
            temp_b = b
            b = c
            a = temp_b

        return c
