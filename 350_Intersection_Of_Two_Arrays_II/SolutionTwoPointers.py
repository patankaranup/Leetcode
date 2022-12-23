class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1 , nums2 = sorted(nums1), sorted(nums2)
        n,m = len(nums1), len(nums2)
        p1 = p2 = 0
        result = []
        while p1<n and p2<m:
            if nums1[p1] == nums2[p2]:
                result.append(nums1[p1])
                p1+=1
                p2+=1
                
            elif nums1[p1] > nums2[p2]:
                p2+=1
            else :
                p1+=1

        return result


    
