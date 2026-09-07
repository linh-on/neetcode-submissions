class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        differenceMap = {}
        for i in range(len(nums)):
            difference = target - nums[i]

            if difference not in differenceMap:
                differenceMap[nums[i]] = i
            else:
                answer = [differenceMap[difference], i]
                return answer

        