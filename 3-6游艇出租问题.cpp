#include <iostream>
#include <memory.h>
#include <stdio.h>
#define N 200
using namespace std;
int r[N][N];    //�洢��������
int p[N][N];    //��¼��С����
int smallestFee(int start, int n);    //����С����
int answer[N];

int main()
{
	int n;
	while (1 == scanf_s("%d", &n)) //��ȡ����
	{
		memset(answer, 0, sizeof(answer));
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n - 1; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
				scanf_s("%d", &r[i][j]);
		}
		printf("��С����: %d\n", smallestFee(1, n));  //�����С����
		//�������
		
		while (getchar() != '\n')    //�޳������ַ���Ϊ��һ��������׼��
			continue;
	}
	return 0;
}
/*�Ե����ϼ���*/
int smallestFee(int start, int n)
{
	//������ѭ�����������ң����������´�ͣ���黹��֮ͧǰ����С����
	for (int i = 2; i <= n; ++i)
	{
		int x = 2 << 10;
		int temp;
		for (int j = 1; j < i; ++j)
		{
			//�����1��jվ����С���ü��ϴ�jֱ�ӵ�iվ�ķ��ñ�֮ǰ�����ŷ������ţ���ѡ�����ַ���
			if (r[j][i] + p[1][j] < x)
			{
				x = r[j][i] + p[1][j];
				temp = j;
			}
		}
		p[1][i] = x;            //��¼���ٻ���
		answer[temp] = temp;    //��¼���ŷ����Ĺ黹վ��
	}
	return p[start][n];
}
