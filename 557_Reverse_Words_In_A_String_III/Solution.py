class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Another better way we can do it in c++
        words = s.split()
        res = []
        for word in words:
            res.append(word[::-1])
            res.append(" ")
        return "".join(res).strip()
