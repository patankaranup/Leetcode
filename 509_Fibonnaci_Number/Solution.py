class Solution(object):
    
    def fib(self, n, memo={}):
        """
        :type n: int
        :rtype: int
        """
        if n in memo:
            return memo[n]
        if n == 0:
            return 0
        if n ==1 :
            return 1
        memo[n] = self.fib(n-1,memo)+self.fib(n-2,memo)
        return memo[n]
    
