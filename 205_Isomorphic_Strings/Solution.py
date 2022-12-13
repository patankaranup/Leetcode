class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        map_S_T, map_T_S = {}, {}
        for c1, c2 in zip(s, t):
            if (c1 in map_S_T and map_S_T[c1] != c2) or (c2 in map_T_S and map_T_S[c2] != c1):
                return False
            else:
                map_S_T[c1] = c2
                map_T_S[c2] = c1
        return True
