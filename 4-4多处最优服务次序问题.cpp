
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[1000];
int ser[100];//服务窗口的顾客等待时间
int sum[100];//服务窗口顾客等待时间的总和。
int main()
{
	int n, s;
	printf_s("请分别输入顾客和共有服务处：");
	while (~scanf_s("%d%d", &n, &s))
	{
		printf_s("服务时间：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &a[i]);
		}
		sort(a, a + n);
		memset(ser, 0, sizeof(ser));
		memset(sum, 0, sizeof(sum));
		int i = 0;
		int j = 0;
		while (i < n)
		{
			ser[j] += a[i];
			sum[j] += ser[j];
			i++, j++;
			if (j == s)
				j = 0;

		}
		double t = 0;
		for (int i = 0; i < n; i++)
		{
			t += sum[i];
		}
		t /= n;
		printf_s("等待时间：");
		printf_s("%0.3lf\n", t);
	}
	return 0;
}
