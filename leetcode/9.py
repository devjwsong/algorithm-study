class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        str_x = str(x)
        for d, digit in enumerate(str_x):
            if digit != str_x[len(str_x)-d-1]:
                return False

        return True

if __name__=="__main__":
    sol = Solution()

    x = int(input("x: "))
    print(sol.isPalindrome(x))
