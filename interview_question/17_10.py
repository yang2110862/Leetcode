class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        candidate = -1
        cnt = 0
        for num in nums:
            if cnt == 0:
                candidate = num
            if num == candidate:
                ++cnt
            else:
                --cnt
        cnt = 0
        n = len(nums)
        for num in nums:
            if num == candidate:
                ++cnt
        if cnt > n / 2:
            return candidate
        else:
            return true
