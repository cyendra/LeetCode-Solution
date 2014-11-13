#include <cstring>
#include <vector>
class Solution {
private:
	void getFail(char P[], vector<int> &f){
		int i = 0, j = -1;
		int len = strlen(P);
		f.resize(len + 1);
		f[0] = -1;
		while (i<len){
			if (j == -1 || P[i] == P[j]){
				i++, j++;
				f[i] = j;
			}
			else{
				j = f[j];
			}
		}
	}

	int KMP(char T[], char P[], vector<int> &f){
		int i = 0, j = 0;
		int n = strlen(T);
		int m = strlen(P);
		getFail(P, f);
		while (i<n){
			if (j == -1 || T[i] == P[j]){
				i++, j++;
			}
			else{
				j = f[j];
			}
			if (j == m){
				// TO DO:  
				//ans++;
				return i - m;
			}
		}
		return -1;
	}
public:
	int strStr(char *haystack, char *needle) {
		int len = strlen(haystack);
		if (strlen(needle) == 0) return 0;
		//cout << len;
		vector<int> f;
		//int *f = new int[len + len];
		//int f[1024];
		//getFail(haystack, f);
		int p = 0;
		p = KMP(haystack, needle, f);
		//delete[] f;
		return p;
	}
};