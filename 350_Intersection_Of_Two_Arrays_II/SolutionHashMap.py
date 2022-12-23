class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hashMap = {}
        result = []
        for n in nums1:
            hashMap[n] = hashMap.get(n , 0)+1

        for n in nums2:
            if n in hashMap and hashMap[n]>0:
                result.append(n)
                hashMap[n] -= 1

        return result
