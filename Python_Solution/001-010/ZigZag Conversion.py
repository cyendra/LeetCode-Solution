class Solution:
    # @return a string
    def convert(self, s, nRows):
        rot = nRows + nRows - 2
        if rot == 0:
            return s
        res = ""
        strs = []
        for i in xrange(nRows):
            strs.append("")
        for i in xrange(len(s)):
            x = i / rot
            y = i % rot
            if y < nRows:
                strs[y] = strs[y] + s[i]
            else:
                strs[2 * nRows - y - 2] = strs[2 * nRows - y - 2] + s[i]
        res = ""
        for i in xrange(nRows):
            res+= strs[i]
        return res

s = "PAYPALISHIRING"
sol = Solution()
sol.convert(s,3)
                
