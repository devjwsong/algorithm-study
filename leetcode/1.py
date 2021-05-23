from typing import List

class Solution:
    def two_sum(self, nums: List[int], target: int) -> List[int]:
        for s, start in enumerate(nums):
            for e, end in enumerate(nums):
                if s != e:
                    if start + end == target:
                        return [s, e]


if __name__=="__main__":
    sol = Solution()

    nums = [int(x) for x in input("nums: ").split()]
    target = int(input("target: "))

    print(sol.two_sum(nums, target))
