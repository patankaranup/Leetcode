class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = 0
        r = 1
        maxP = 0
        while r < len(prices):
            if prices[l] > prices[r]:
                l = r
            else:
                curProf = prices[r]-prices[l]
                maxP = max(curProf, maxP)
                r+=1

        
        return maxP

