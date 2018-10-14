def add_a(a):
    def fun(x):
        return a+x
    return fun

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        pair = []
        if(k<=0 or  0==len(nums1) or 0==len(nums2)):
            return pair
        
        nums1=nums1[:k]
        nums2=nums2[:k]
        
        # pair = [[a,b] for a in nums1 for b in nums2]
        # return pair
        all_sums = []
        for a in nums1:
            all_sums += map(add_a(a), nums2)

        all_sums.sort()

        print("all_sums:", all_sums)

        max_sum=all_sums[k-1]

        print("max_sum:", max_sum)

        for a in nums1:
            for b in nums2:
                if(a + b < max_sum):
                    pair.append([a,b])

        while(k > len(pair)):
            for a in nums1:
                if(max_sum-a in nums2):
                    pair.append([a, max_sum -a])
        return pair
                    


            
        
if "__main__" == __name__:
    nums1=[1,4,7,11]
    nums2=[2,4,5,11]
    k=5
    print('nums1:', nums1)
    print('nums2:', nums2)
    print('k:', k)

    s = Solution()
    res = s.kSmallestPairs(nums1,nums2,k)
    print('solution:', res)