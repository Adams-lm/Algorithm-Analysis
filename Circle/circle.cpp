#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 100

double x[N], r[N];//最小圆排列长度，圆心横坐标数组，圆半径数组
double bestsort[N];//最小圆排列半径顺序
double Min = 0x3f3f3f3f;//无穷大
int n;//圆个数

double center(int n) {//计算圆心横坐标
	double length = 0;
	for (int i = 0; i < n; i++) {//判断圆是否与排在它之前的任一圆相切
		double temp = x[i] + 2.0 * sqrt(r[n] * r[i]);//前一圆的圆心横坐标加两圆圆心横间距
		if (temp > length)
			length = temp;
	}
	return length;
}
void compute() {//计算当前圆排列长度
	double low = 0, high = 0;
	for (int i = 1; i <= n; i++) {//找到最左和最右圆心横坐标
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < Min) {//将圆排列长度与最小值比较 决定是否进行更新
		Min = high - low;
		for (int i = 1; i <= n; ++i)
			bestsort[i] = r[i];
	}
}
void backtrack(int t) {
	if (t == n + 1)//最后一个圆
		compute();//计算圆排列长度
	else {
		for (int i = t; i <= n; ++i) {
			swap(r[t], r[i]);//全排列
			double centerX = center(t);
			if (centerX + r[t] + r[1] < Min) {//先判断是否在范围内，如果是则不断搜索下一层，如果不是直接回溯。
				x[t] = centerX;
				backtrack(t + 1);
			}
			swap(r[t], r[i]);//全排列换回
		}
	}
}
int main()
{
	cout << "请输入圆的个数：";
	cin >> n;
	cout << "请依次输入圆的半径：" ;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	backtrack(1);
	cout << "最优圆排列长度为：" << Min << endl;
	cout << "最优圆排列顺序为：";
	for (int i = 1; i <= n; ++i)
		cout<<bestsort[i]<<" ";
}

