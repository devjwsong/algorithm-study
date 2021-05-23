class Solution:
    def romanToInt(self, s: str) -> int:
        s2v = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900
        }

        value = 0
        cur = 0
        while cur < len(s):
            if s[cur:cur+2] in s2v:
                value += s2v[s[cur:cur+2]]
                cur += 2
            else:
                value += s2v[s[cur]]
                cur += 1

        return value



if __name__=="__main__":
    sol = Solution()

    s = input("s: ")
    print(sol.romanToInt(s))
