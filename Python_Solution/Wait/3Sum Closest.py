class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        num.sort()
        n = len(num)
        ans = 0x3f3f3f3f
        res = 0
        for p in range(n):
            L = 0
            R = n - 1
            while L < R:
                if L == p:
                    L += 1
                    continue
                if R == p:
                    R -= 1
                    continue
                sum = num[L] + num[R] + num[p]
                if abs(sum - target) < ans:
                    ans = abs(sum - target)
                    res = sum
                if sum < target:
                    L += 1
                elif sum > target:
                    R -= 1
                else:
                    ans = 0
                    res = sum
                    break
        return res

sol = Solution()
print sol.threeSumClosest([-1,2,1,-4],1)
