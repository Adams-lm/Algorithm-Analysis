#include<iostream>
using namespace std;
const int MAX = 1000, INF = 9999999;
int cost[MAX][MAX];//��ά���鶨��ȫ�ֱ�������������ջ��cost��������ͨ��Ȩͼ���ڽӾ��� 
int m,n,sumweight;//���嶨������������Ȩ�غ� 

int Prim(int start)//startΪ��ʼ���� 
{
	int lowcost[MAX];//��СȨֵ
	int closest[MAX];//ǰ׺����
	bool S[MAX];//����S 
	cout<<"Prim:"<<endl;
	for (int i = 1; i <= n; i++)
	{
		lowcost[i] = cost[start][i];//���ඥ���붥��start����С����
		closest[i] = start;
		S[i] = false;//��ʼ������SΪ�� 
	}
	S[start] = true;//����start���뼯��S
	for (int i = 1; i < n; i++)//��������n-1������
	{
		int min = INF;
		int j = start;
		for (int k = 1; k <= n; k++)
		{
			if ((lowcost[k] < min) && (!S[k]))//�ҵ����ڼ���S�е���С��Ȩ�Ķ���j
			{
				min = lowcost[k];
				j = k;
			}
		}
		sumweight += lowcost[j];
		S[j] = true;//����j����S����
		cout << closest[j] << "->" << j << ":" << lowcost[j] << endl;//�������·��
		for (int k = 1; k <= n; k++)//����j����S���Ϻ�Ҫ����lowcost��closest 
			if ((!S[k]) && (cost[j][k] < lowcost[k]))
			{
				lowcost[k] = cost[j][k];
				closest[k] = j;
			}
	}
	return sumweight;
}
int main() {
	int start;//���
	int j, k, weight;//����j��k֮���Ȩ��weight 
	cin >> n >> m >> start;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cost[i][j] = INF;//��ֵ�����
	for (int i = 1; i <= m; i++)
	{
		cin >> j >> k >> weight;
		cost[j][k] = cost[k][j] = weight;
	}
	cout << "the minimum sumweight is " << Prim(start) << endl;
}
