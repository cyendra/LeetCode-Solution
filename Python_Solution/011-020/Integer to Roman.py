class Solution:
    # @return a string
    def intToRoman(self, num):
        s = ""
        if num >= 1000:
            i = num / 1000
            for j in range(i):
                s = s + "M"
            num -= 1000 * i
        if num >= 900:
            s = s + "CM"
            num -= 900
        if num >= 500:
            s = s + "D"
            num -= 500
        if num >= 400:
            s = s + "CD"
            num -= 400
        if num >= 100:
            i = num / 100
            for j in range(i):
                s = s + "C"
            num -= 100 * i
        if num >= 90:
            s = s + "XC"
            num -= 90
        if num >= 50:
            s = s + "L"
            num -= 50
        if num >= 40:
            s = s + "XL"
            num -= 40
        if num >= 10:
            i = num / 10
            for j in range(i):
                s = s + "X"
            num -= 10 * i
        if num >= 9:
            s = s + "IX"
            num -= 9
        if num >= 5:
            s = s + "V"
            num -= 5
        if num >= 4:
            s = s + "IV"
            num -= 4
        for j in range(num):
            s = s + "I"
        return s


sol = Solution()
print sol.intToRoman(233)