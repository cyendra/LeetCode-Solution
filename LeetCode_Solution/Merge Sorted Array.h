#include <algorithm>
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int p = 0, q = 0;
		int cnt = 0;
		int *C = new int[n + m];
		while (p < m && q < n) {
			if (A[p] < B[q]) {
				C[cnt++] = A[p++];
			}
			else {
				C[cnt++] = B[q++];
			}
		}
		if (p < m) {
			for (int i = p; i < m; i++) {
				C[cnt++] = A[i];
			}
		}
		if (q < n) {
			for (int i = q; i < n; i++) {
				C[cnt++] = B[i];
			}
		}
		for (int i = 0; i < n + m; i++){
			A[i] = C[i];
		}
		delete[] C;
	}
};