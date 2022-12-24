class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        lon_palindrome = 0
        hashMap = {}
        odd_found = False
        for letter in s:
            if letter in hashMap:
                hashMap[letter]+=1
            else:
                hashMap[letter] = 1
        for key in hashMap:
            if hashMap[key] % 2 == 0:
                lon_palindrome += hashMap[key]
            else:
                odd_found = True
                lon_palindrome += hashMap[key] -1  
        if odd_found:
            lon_palindrome +=1

        return lon_palindrome

            
