class Solution:
    # @return an integer
    def maxArea(self, height):
        n = len(height)
        L = 0
        R = n - 1
        ans = 0
        while L < R:
            tmp = (R - L) * min(height[L], height[R])
            if tmp > ans:
                ans = tmp
            if height[L] < height[R]:
                b = height[L]
                while L < n and height[L] <= b:
                    L += 1
            else:
                b = height[R]
                while R >= 0 and height[R] <= b:
                    R -= 1
        return ans
sol = Solution()
print sol.maxArea([1,1])