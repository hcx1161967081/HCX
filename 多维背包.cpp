#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;
int n;//物品数量
int m ;//约束条件
double c[50];//背包容量
double v[100];//各个物品的价值
double w[100][100];//各个物品的重量
double cp = 0.0;//当前背包中物品价值
double bestp = 0.0;//当前最优价值
double put[100];//当前背包重量
int x ;//用来判断

//回溯函数
void backtrack(int i)
{

	if (i >= n)
	{
		if (cp > bestp)
			bestp = cp;
		return;
	}
	for (int j = 0; j < m; j++) {
	double	cw = put[j] + w[j][i];
		if (cw - c[j] <= 0)
			x = 1;
		else
			x=0;
	if (x==0)
		break;
			
	}
		if (x==1) {
			for (int j = 0; j < m; j++)
				put[j] += w[j][i];
			cp += v[i];
			backtrack(i + 1);
			for (int j = 0; j < m; j++)
				put[j] -= w[j][i];//此处回溯
			cp -= v[i];
		}
	//符合条件搜索右子数

	backtrack(i + 1);
}


int main()
{	
	ifstream file("input4.txt");
	file >> n >> m;
	for (int i = 0; i < n; i++)
		file >> v[i];
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			file >> w[j][i];
	for (int i = 0; i < m; i++)
		file >> c[i];
	backtrack(0);
	printf("最优价值为：%lf\n", bestp);
	file.close();
	return 0;
}