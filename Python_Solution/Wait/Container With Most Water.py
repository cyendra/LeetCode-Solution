class Solution:
    # @return an integer
    def maxArea(self, height):
        n = len(height)
        ans = 0
        for i in xrange(n):
            for j in xrange(i):
                res = min(i,j) * j - i
                if res > ans:
                    ans = res
        return ans