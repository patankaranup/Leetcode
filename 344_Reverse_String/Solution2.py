class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        def reverse_string(l, r):
            if l <= r:
                s[l], s[r] = s[r], s[l]
                reverse_string(l+1, r-1)
        reverse_string(0, len(s)-1)
