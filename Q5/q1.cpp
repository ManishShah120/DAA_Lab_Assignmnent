//5 Dynamic Programming
//5.1 Implement the Bottom Up Dynamic Programming Approach for matrix chain multiplication.
//SOURCE techiedelight.com

#include <iostream>
#include <climits>
using namespace std;

int MatrixChainMultiplication(int dims[], int n)
{
	int c[n + 1][n + 1];

	for (int i = 1; i <= n; i++)
		c[i][i] = 0;

	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			c[i][j] = INT_MAX;

			for (int k = i; j < n && k <= j - 1; k++)
			{
				int cost = c[i][k] + c[k + 1][j] + dims[i - 1]*dims[k]*dims[j];
				if (cost < c[i][j])
					c[i][j] = cost;
			}
		}
	}
	return c[1][n - 1];
}

int main()
{
	int dims[] = { 10, 30, 5, 60 };
	int n = sizeof(dims) / sizeof(dims[0]);

	cout << "Answer: " << MatrixChainMultiplication(dims, n);
	cout<<"\n";
	return 0;
}
