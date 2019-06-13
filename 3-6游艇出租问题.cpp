#include <iostream>
#include <memory.h>
#include <stdio.h>
#define N 200
using namespace std;
int r[N][N];    //存储费用数据
int p[N][N];    //记录最小花费
int smallestFee(int start, int n);    //求最小费用
int answer[N];

int main()
{
	int n;
	while (1 == scanf_s("%d", &n)) //读取数据
	{
		memset(answer, 0, sizeof(answer));
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n - 1; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
				scanf_s("%d", &r[i][j]);
		}
		printf("最小费用: %d\n", smallestFee(1, n));  //输出最小费用
		//输出方案
		
		while (getchar() != '\n')    //剔除后续字符，为下一次输入做准备
			continue;
	}
	return 0;
}
/*自底向上计算*/
int smallestFee(int start, int n)
{
	//这两层循环，由左至右，计算了在下次停靠归还游艇之前的最小费用
	for (int i = 2; i <= n; ++i)
	{
		int x = 2 << 10;
		int temp;
		for (int j = 1; j < i; ++j)
		{
			//如果从1到j站的最小费用加上从j直接到i站的费用比之前的最优方案更优，则选择这种方案
			if (r[j][i] + p[1][j] < x)
			{
				x = r[j][i] + p[1][j];
				temp = j;
			}
		}
		p[1][i] = x;            //记录最少花费
		answer[temp] = temp;    //记录最优方案的归还站点
	}
	return p[start][n];
}
