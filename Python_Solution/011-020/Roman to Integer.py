class Solution:
    # @return an integer
    def romanToInt(self, s):
        n = len(s)
        p = 0
        num = 0
        cnt = 0
        while p < n:
            if s[p] == 'M':
                cnt = 0
                while p < n and s[p] == 'M':
                    cnt += 1
                    p += 1
                num += 1000 * cnt
            elif p + 1 < n and s[p:p+2] == 'CM':
                num += 900
                p += 2
            elif s[p] == 'D':
                num += 500
                p += 1
            elif p + 1 < n and s[p:p+2] == 'CD':
                num += 400
                p += 2
            elif s[p] == 'C':
                cnt = 0
                while p < n and s[p] == 'C':
                    cnt += 1
                    p += 1
                num += 100 * cnt
            elif p + 1 < n and s[p:p+2] == 'XC':
                num += 90
                p += 2
            elif s[p] == 'L':
                num += 50
                p += 1
            elif p + 1 < n and s[p:p+2] == 'XL':
                num += 40
                p += 2
            elif s[p] == 'X':
                cnt = 0
                while p < n and s[p] == 'X':
                    cnt += 1
                    p += 1
                num += 10 * cnt
            elif p + 1 < n and s[p:p+2] == 'IX':
                num += 9
                p += 2
            elif s[p] == 'V':
                num += 5
                p += 1
            elif p + 1 < n and s[p:p+2] == 'IV':
                num += 4
                p += 2
            elif s[p] == 'I':
                cnt = 0
                while p < n and s[p] == 'I':
                    cnt += 1
                    p += 1
                num += cnt
        return num

sol = Solution()
print sol.romanToInt("DCXXI")
