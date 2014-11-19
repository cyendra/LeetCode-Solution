class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        ans = []
        num.sort()
        n = len(num)
        lst = 0
        for i in xrange(n - 2):
            if i==0 or num[i] != lst:
                l = i + 1
                r = n - 1
                while l < r:
                    #print l,r
                    #print [num[i], num[l], num[r]],l,r
                    if -num[i] == num[l] + num[r]:
                        ans.append([num[i], num[l], num[r]])
                        l+=1
                        r-=1
                        while l < r and num[l] == num[l - 1]:
                            l+=1
                        while l < r and num[r] == num[r + 1]:
                            r-=1
                    elif -num[i] < num[l] + num[r]:
                        r-=1
                        while l < r and num[r] == num[r + 1]:
                            r-=1
                    elif -num[i] > num[l] + num[r]:
                        l+=1
                        while l < r and num[l] == num[l - 1]:
                            l+=1
                lst = num[i]
        return ans  
                  
s1 = [-1,0,1]
s = [-1, 0, 1, 2, -1 ,-4]
s2 = [7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6]
sol = Solution()
print sol.threeSum(s1)