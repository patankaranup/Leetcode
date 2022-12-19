class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        stack = []
        for e in s:
            stack.append(e)
        i = 0
        while stack:
            s[i] = stack.pop()
            i += 1
