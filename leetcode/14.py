from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prev_prefix = ""
        for end in range(200):
            
            cur_prefix = strs[0][:end]
            for s in strs[1:]:
                if cur_prefix != s[:end]:
                    return prev_prefix
            prev_prefix = cur_prefix

        return prev_prefix


if __name__=="__main__":
    sol = Solution()

    strs = [x for x in input("strs: ").split()]

    print(sol.longestCommonPrefix(strs))
