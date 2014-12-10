
class Solution:
    def findKth(self, A, A_start, B, B_start, k):
        if A_start >= len(A):
            return B[B_start + k - 1]
        if B_start >= len(B):
            return A[A_start + k - 1]
        if k == 1:
            return min(A[A_start], B[B_start])
        A_key = 0x3f3f3f3f
        if A_start + k / 2 - 1 < len(A):
            A_key = A[A_start + k / 2 - 1]
        B_key = 0x3f3f3f3f
        if B_start + k / 2 - 1 < len(B):
            B_key = B[B_start + k / 2 - 1]
        if A_key < B_key:
            return self.findKth(A, A_start + k / 2, B, B_start, k - k / 2)
        else:
            return self.findKth(A, A_start, B, B_start + k / 2, k - k / 2)
    # @return a float
    def findMedianSortedArrays(self, A, B):
        n = len(A) + len(B)
        if n % 2 == 0:
            return (self.findKth(A, 0, B, 0, n / 2) + self.findKth(A, 0, B, 0, n / 2 + 1)) / 2.0
        else:
            return self.findKth(A, 0, B, 0, n / 2 + 1)

x = Solution()
print x.findMedianSortedArrays([],[1,2,3,4,5])