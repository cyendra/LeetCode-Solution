class Solution {
public:
	int singleNumber(int A[], int n) {
		int b[32];
		for (int k = 0; k < 32; k++)
		{
			b[k] = 0;
			for (int i = 0; i < n; i++)
			{
				if (A[i] & (1 << k))
				{
					b[k]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (b[i] % 3 == 1)
			{
				ans |= (1 << i);
			}
		}
		return ans;
	}
};