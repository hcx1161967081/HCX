#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Job {
	int begin, end;
	bool ok;
};

int manage(int n, Job * b) {
	int count = n, roomavail = 0, roomnum = 0;//count��ʾ��ʣ�༸���δ����
	while (count > 0) {//��count=0���˳�whileѭ��
		for (int i = 1; i <= n; i++) {
			if ((b[i].begin > roomavail) && (b[i].ok == 0)) {//�����ǰ�δ���Ų��Һͻ᳡����   //�л����ͻ
				roomavail = b[i].end;//����ǰ�����û᳡�����Ҹ��»᳡�Ŀ���ʱ��
				b[i].ok = 1;//��Ǹû�ѱ�����
				count--;//δ���ŵĻ����1
			}
		}
		roomavail = 0;//��roomavail��ʼ�����൱����������һ������ 
		roomnum++;//����һ�Σ�ʹ�õĻ᳡����1
	}
	return roomnum;//����ʹ�õĻ᳡��
}

int main() {
	ifstream cinfile;
	cinfile.open("input.txt", ios::in);
	int n, roomnum;
	cinfile >> n;
	Job b[100];
	b[0].begin = 0; b[0].end = 0; b[0].ok = 0;
	for (int i = 1; i <= n; i++) {
		cinfile >> b[i].begin >> b[i].end;
		b[i].ok = 0;
	}
	cinfile.close();

	for (int i = 1; i <= n; i++) {//����
		for (int j = i + 1; j <= n; j++) {
			if (b[i].end > b[j].end) {
				Job Register = b[i];
				b[i] = b[j];
				b[j] = Register;
			}
		}
	}
	roomnum = manage(n, b);

	ofstream outfile;
	outfile.open("output.txt", ios::out);
	outfile << roomnum << endl;
	outfile.close();
	return 0;
}

