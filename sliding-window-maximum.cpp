#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;

unsigned int winLen, totalLen;

bool Max(int x, int y)
{
	return x >= y;
}

bool Min(int x, int y)
{
	return x <= y;
}

void Solve(const int *arr, bool Cmp(int, int))
{
	deque<int> win;

	win.push_back(0);
	for (size_t i = 1; i < winLen; i++)
	{
		while (!win.empty() && Cmp(arr[i], arr[win.back()]))	// hash的意味
		{
			win.pop_back();
		}
		win.push_back(i);	// NOTE
	}
	printf("%d", arr[win.front()]);

	for (size_t i = winLen; i < totalLen; i++)
	{
		// 之后每push一个进去时，之前就测试有没有在winLen之前的元素，若有则pop掉
		while (i - win.front() >= winLen)
		{
			win.pop_front();
		}

		// push进去之前扫掉前面比它小(大)的
		while (!win.empty() && Cmp(arr[i], arr[win.back()]))
		{
			win.pop_back();
		}
		win.push_back(i);

		printf(" %d", arr[win.front()]);
	}
}

int main(void)
{
	//	freopen("cin.txt", "r", stdin);
	cin >> totalLen >> winLen;
	int *arr = new(nothrow) int[totalLen];
	if (arr == NULL)
	{
		cout << "OVERFLOW" << endl;
		exit(-3);
	}

	for (size_t i = 0; i < totalLen; i++)
	{
		int elem;
		scanf("%d", &elem);
		arr[i] = elem;		
	}

	Solve(arr, Min);
	cout << endl;
	Solve(arr, Max);

	delete[] arr;
	arr = NULL;
	return 0;
}
