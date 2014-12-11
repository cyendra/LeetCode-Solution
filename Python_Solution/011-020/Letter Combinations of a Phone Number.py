class Solution:
    def gao(self, dep):
        if dep == self.n:
            s = ""
            for c in self.s:
                s+=c
            self.ans.append(s)
            return
        idx = int(self.digits[dep])
        for i in range(len(self.phone[idx])):   
            self.s.append(self.phone[idx][i])
            self.gao(dep+1)
            self.s.pop()
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        self.phone = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        self.ans = []
        self.n = len(digits)
        self.s = []
        self.digits = digits
        self.gao(0)
        return self.ans

sol = Solution()
print sol.letterCombinations("23")