class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        max_wealth = 0
        for i in range(0, len(accounts)):
            sum = 0
            for j in range(0,len(accounts[i])):
                sum += accounts[i][j]
            max_wealth = max(max_wealth, sum)
        return max_wealth 
        
            
