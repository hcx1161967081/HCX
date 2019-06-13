#include<stdio.h>
#define n 3    //部件数
#define m 3    //供应商
#define d 4    //总价格不超过d
int w[n][n] = { 1,2,3,3,2,1,2,2,2 }, c[n][n] = { 1,2,3,3,2,1,2,2,2 };
int a[n] = { 0 }, final[n] = { 0 }; //final记录部件的最终供应商，a记录过程中的供应商 
int minweight = 1000000;      //最终的最小质量
int weight = 0, value = 0;     //两个过程值
void traceback(int t) {
	if (t == 3 && value <= d) {
		if (weight < minweight) {
			minweight = weight;
			for (int k = 0; k < n; k++) {
				final[k] = a[k];
			}
		}
		return;
	}
	if (value <= d) {
		for (int i = 0; i < m; i++) {  //遍历的是供应商 
			a[t] = i; //记录一下当前的这个部件是从哪个供应商购得
			weight += w[t][i];
			value += c[t][i];
			traceback(t + 1);
			value -= c[t][i];
			weight -= w[t][i];
			a[t] = 0;
		}
	}
}

int main() {
	traceback(0);           //t代表部件 
	printf("最小重量是：%d\n", minweight);
	for (int i = 0; i < n; i++)
		printf("%3d", final[i] + 1);
	printf("\n");
	return 0;
}