//5 Dynamic Programming
//5.2. Implement the Top Down Dynamic Programming Memoization Approach for matrix chain multiplication.
//SOURCE techiedelight.com

#include <iostream>
#include <climits>
using namespace std;
#define MAX 10

int lookup[MAX][MAX];

int MatrixChainMultiplication(int dims[], int i, int j)
{
	if (j <= i + 1)
		return 0;
	int min = INT_MAX;
	if (lookup[i][j] == 0)
	{
		for (int k = i + 1; k <= j - 1; k++)
		{
			int cost = MatrixChainMultiplication(dims, i, k);
			cost += MatrixChainMultiplication(dims, k, j);
			cost +=	dims[i] * dims[k] * dims[j];
			if (cost < min)
				min = cost;
		}
		lookup[i][j] = min;
	}
	return lookup[i][j];
}

int main()
{
	int dims[] = {30, 40, 21, 5, 6, 10 };
	int n = sizeof(dims) / sizeof(dims[0]);

	cout << "Answer: " << MatrixChainMultiplication(dims, 0, n - 1);
	cout<<endl;
	return 0;
}
