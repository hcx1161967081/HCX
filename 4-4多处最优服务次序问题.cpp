
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[1000];
int ser[100];//���񴰿ڵĹ˿͵ȴ�ʱ��
int sum[100];//���񴰿ڹ˿͵ȴ�ʱ����ܺ͡�
int main()
{
	int n, s;
	printf_s("��ֱ�����˿ͺ͹��з��񴦣�");
	while (~scanf_s("%d%d", &n, &s))
	{
		printf_s("����ʱ�䣺");
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
		printf_s("�ȴ�ʱ�䣺");
		printf_s("%0.3lf\n", t);
	}
	return 0;
}
