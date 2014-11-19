class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        n=A.count(elem)
        for i in range(n):
            A.remove(elem)
        return len(A)