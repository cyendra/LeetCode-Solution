import re

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        p = re.compile(p)
        rs = p.match(s)
        if rs.start() == 0 and rs.end() == len(s):
            return True
        else:
            return False


fun = Solution()
print fun.isMatch("abc", "abc")