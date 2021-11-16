#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** t, const int n, const int Low, const int High, int i, int j)
{
	t[i][j] = Low + rand() % (High - Low + 1);

	if (j < n - 1)
		Create(t, n, Low, High, i, j + 1);
	else
		if (i < n - 1)
			Create(t, n, Low, High, i + 1, 0);
}

void Print(int** t, const int n, int i, int j)
{
	cout << setw(4) << t[i][j];
	if (j < n - 1)
		Print(t, n, i, j + 1);
	else
		if (i < n - 1)
		{
			cout << endl;
			Print(t, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Transpose(int** t, const int n, int i, int j)
{
	int tmp = t[i][j];
	t[i][j] = t[j][i];
	t[j][i] = tmp;

	if (j < i - 1)
		Transpose(t, n, i, j + 1);
	else
		if (i < n - 1)
			Transpose(t, n, i + 1, 0);
}

int main()
{
	srand((unsigned)time(NULL));

	int Low = -15;
	int High = 15;

	int n;
	cout << "n = "; cin >> n;

	int** t = new int* [n];
	for (int i = 0; i < n; i++)
		t[i] = new int[n];

	Create(t, n, Low, High, 0, 0);
	cout << endl;
	Print(t, n, 0, 0);

	Transpose(t, n, 0, 0);
	Print(t, n, 0, 0);

	for (int i = 0; i < n; i++)
		delete[] t[i];
	delete[] t;

	return 0;
}
