class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int cnt = 0;
		if (n > 0) cnt = 1;
		for (int i = 0; i < n-1; i++) {
			if (A[i] != A[i + 1]) A[cnt++] = A[i + 1];
		}
		return cnt;
	}
};