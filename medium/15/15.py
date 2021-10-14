from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i == 0 or nums[i-1] != nums[i]:
                self.twoSum(nums, i, ans)
        return ans
    
    def twoSum(self, nums:List[int], i:int, ans:List[List[int]]):
        seen = set()
        j = i + 1
        while j < len(nums):
            complement = -nums[i]-nums[j]
            if complement in seen:
                ans.append([nums[i], nums[j], complement])
                while j+1 < len(nums) and nums[j] == nums[j+1]:
                    j += 1
            seen.add(nums[j])
            j += 1

sol = Solution()
nums = list(map(int, input().split()))
print(sol.threeSum(nums))