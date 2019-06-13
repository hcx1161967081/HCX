#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Job {
	int begin, end;
	bool ok;
};

int manage(int n, Job * b) {
	int count = n, roomavail = 0, roomnum = 0;//count表示还剩余几个活动未安排
	while (count > 0) {//当count=0就退出while循环
		for (int i = 1; i <= n; i++) {
			if ((b[i].begin > roomavail) && (b[i].ok == 0)) {//如果当前活动未安排并且和会场中已   //有活动不冲突
				roomavail = b[i].end;//将当前活动加入该会场，并且更新会场的空闲时间
				b[i].ok = 1;//标记该活动已被安排
				count--;//未安排的活动数减1
			}
		}
		roomavail = 0;//把roomavail初始化，相当于重新再找一个房间 
		roomnum++;//遍历一次，使用的会场数加1
	}
	return roomnum;//返回使用的会场数
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

	for (int i = 1; i <= n; i++) {//排序
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

