#include <iostream>
using namespace std;
unsigned int func(int* L, int* R, int size, int i, int* prevL)
{
	if(R[i] < L[i])
		return 0;

	int l = L[i];
	if(l < 0)
		l = prevL[-l - 1];

	if(i + 1 == size)
		return R[i] - l + 1;

	int count = 0;
	for(int j = l; j <= R[i]; j++)
	{
		prevL[i] = j;
		count += func(L, R, size, i + 1, prevL);
	}

	return count;
}

int main()
{
	int n;
	cin >> n;
	int *L = new int[n];
	int *R = new int[n];
	int *Levels = new int[n];
	for(int i = 0; i < n; i++)
		cin >> L[i] >> R[i];

	unsigned int k = func(L, R, n, 0, Levels);
	cout << k;

	delete[]L;
	delete[]R;
	delete[]Levels;
	return 0;
}
