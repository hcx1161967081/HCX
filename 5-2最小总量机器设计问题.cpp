#include<stdio.h>
#define n 3    //������
#define m 3    //��Ӧ��
#define d 4    //�ܼ۸񲻳���d
int w[n][n] = { 1,2,3,3,2,1,2,2,2 }, c[n][n] = { 1,2,3,3,2,1,2,2,2 };
int a[n] = { 0 }, final[n] = { 0 }; //final��¼���������չ�Ӧ�̣�a��¼�����еĹ�Ӧ�� 
int minweight = 1000000;      //���յ���С����
int weight = 0, value = 0;     //��������ֵ
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
		for (int i = 0; i < m; i++) {  //�������ǹ�Ӧ�� 
			a[t] = i; //��¼һ�µ�ǰ����������Ǵ��ĸ���Ӧ�̹���
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
	traceback(0);           //t������ 
	printf("��С�����ǣ�%d\n", minweight);
	for (int i = 0; i < n; i++)
		printf("%3d", final[i] + 1);
	printf("\n");
	return 0;
}