#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 100

double x[N], r[N];//��СԲ���г��ȣ�Բ�ĺ��������飬Բ�뾶����
double bestsort[N];//��СԲ���а뾶˳��
double Min = 0x3f3f3f3f;//�����
int n;//Բ����

double center(int n) {//����Բ�ĺ�����
	double length = 0;
	for (int i = 0; i < n; i++) {//�ж�Բ�Ƿ���������֮ǰ����һԲ����
		double temp = x[i] + 2.0 * sqrt(r[n] * r[i]);//ǰһԲ��Բ�ĺ��������ԲԲ�ĺ���
		if (temp > length)
			length = temp;
	}
	return length;
}
void compute() {//���㵱ǰԲ���г���
	double low = 0, high = 0;
	for (int i = 1; i <= n; i++) {//�ҵ����������Բ�ĺ�����
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < Min) {//��Բ���г�������Сֵ�Ƚ� �����Ƿ���и���
		Min = high - low;
		for (int i = 1; i <= n; ++i)
			bestsort[i] = r[i];
	}
}
void backtrack(int t) {
	if (t == n + 1)//���һ��Բ
		compute();//����Բ���г���
	else {
		for (int i = t; i <= n; ++i) {
			swap(r[t], r[i]);//ȫ����
			double centerX = center(t);
			if (centerX + r[t] + r[1] < Min) {//���ж��Ƿ��ڷ�Χ�ڣ�������򲻶�������һ�㣬�������ֱ�ӻ��ݡ�
				x[t] = centerX;
				backtrack(t + 1);
			}
			swap(r[t], r[i]);//ȫ���л���
		}
	}
}
int main()
{
	cout << "������Բ�ĸ�����";
	cin >> n;
	cout << "����������Բ�İ뾶��" ;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	backtrack(1);
	cout << "����Բ���г���Ϊ��" << Min << endl;
	cout << "����Բ����˳��Ϊ��";
	for (int i = 1; i <= n; ++i)
		cout<<bestsort[i]<<" ";
}

