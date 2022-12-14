class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i = 0  # two pointers
        j = 0  # two pointers
        while (i < len(s) and j < len(t)):  # if s and t are still iterable
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        return True if i == len(s) else False
