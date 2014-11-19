class Solution:
    def gao(self, s1, s2):
        p = 0
        l = min(len(s1), len(s2))
        while p < l:
            if s1[p] != s2[p]:
                return p
            p += 1
        return p
    # @return a string
    def longestCommonPrefix(self, strs):
        n = len(strs)
        if n == 0:
            return ""
        elif n == 1:
            return strs[0]
        else:
            s = strs[0]
            for i in xrange(1, n):
                p = self.gao(s, strs[i])
                s = s[0:p]
            return s

strs=["abcde","ab","abcff"]
sol = Solution()
print sol.longestCommonPrefix(strs)