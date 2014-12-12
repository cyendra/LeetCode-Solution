class Solution:
    def check(self, p):
        #print "-------------------\n", p
        L = R = p
        cnt = 0
        maxcnt = len(self.L)
        while L + self.len <= len(self.S) and R + self.len <= len(self.S):
            word = self.S[R:R+self.len]
            #print L,R,cnt,word
            if self.dict.has_key(word) == False:
                L = R = R + self.len
                cnt = 0
                self.book = {}
                continue
            if self.book.has_key(word) == False:
                self.book[word] = 0
            self.book[word] += 1
            cnt += 1
            R += self.len
            while self.book[word] > self.dict[word]:
                pre = self.S[L:L+self.len]
                self.book[pre] -= 1
                cnt -= 1
                L += self.len
            if cnt == maxcnt:
                self.ans.append(L)

    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        self.L = L
        self.S = S
        self.ans = []
        self.dict = {}
        self.len = len(L[0])
        for c in L:
            if self.dict.has_key(c) == False:
                self.dict[c] = 0
            self.dict[c] += 1
        for i in xrange(self.len):
            self.book = {}
            self.check(i)
        return self.ans

sol = Solution()
print sol.findSubstring("barfoothefoobarman", ["foo","bar"])
print sol.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", ["fooo","barr","wing","ding","wing"])
print sol.findSubstring("a", ["a"])