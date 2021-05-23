class Solution:
    def reverse(self, x: int) -> int:
        is_minus = False
        if x < 0:
            is_minus = True
            x = -1 * x
        
        str_x = str(x)
        reversed_str = ""

        for c in str_x:
            reversed_str =  c + reversed_str

        reversed_x = int(reversed_str)
        if is_minus:
            reversed_x = -1 * reversed_x

        if reversed_x <= (2**31-1) and reversed_x >= (-2**31):
            return reversed_x
        else:
            return 0

if __name__=="__main__":
    sol = Solution()

    x = int(input("x: "))
    print(sol.reverse(x))
