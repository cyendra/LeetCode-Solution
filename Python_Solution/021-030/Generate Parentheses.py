class Solution:
    def gao(self, pl, pr):
        if pl == self.n and pr == self.n:
            gen = ""
            for c in self.gen:
                gen+=c
            self.ans.append(gen)
            return
        if pl < self.n:
            self.stack.append('(')
            self.gen.append('(')
            self.gao(pl + 1, pr)
            self.gen.pop()
            self.stack.pop()
        if len(self.stack) > 0 and pr < self.n:
            self.stack.pop()
            self.gen.append(')')
            self.gao(pl, pr + 1)
            self.gen.pop()
            self.stack.append('(')
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        self.n = n
        self.ans = []
        self.stack = []
        self.gen = []
        self.gao(0, 0)
        return self.ans

sol = Solution()
print sol.generateParenthesis(3)