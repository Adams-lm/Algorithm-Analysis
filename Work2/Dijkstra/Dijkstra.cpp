#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MAX 1000//������ 
#define INF 0x3f3f3f3f//����� 
using namespace std;
int distmap[MAX][MAX], dist[MAX], visited[MAX], path[MAX];//������󣬵�������룬���ʼ��� 
int n, m, start, End;//������������,��㣬�յ� 
stack<int>Stack;//�洢path��Stack 
void Init()
{
	//��ʼ��
	memset(path, 0, sizeof(path));
	memset(visited, 0, sizeof(visited));
	memset(dist, INF, sizeof(dist));
	memset(distmap, INF, sizeof(distmap));
	cin >> n >> m;//���붥�����ͱ��� 
	int u, v, dis;
	for (int i = 1; i <= m; i++)//����� 
	{
		cin >> u >> v >> dis;
		distmap[u][v] = dis;
	}
	for (int i = 1; i <= n; i++)//���������ʼ��Ϊ0 
		distmap[i][i] = 0;
	cin >> start >> End; //���������յ� 
}
int Dijkstra(int start,int End)
{
	cout << "Dijkstra:" << endl;
	dist[start] = 0;  //���������ľ���Ϊ0
	for (int i = 1; i <= n; i++)
	{
		int u, MIN = INF;
		for (int j = 1; j <= n; j++)//Ѱ�Ҵ�ʱdist[]�е���Сֵ
		{
			if (dist[j] < MIN && visited[j] == 0)
			{
				MIN = dist[j];
				u = j;
			}
		}
		//uΪ�µ����
		visited[u] = 1;  //��·�������м���õ�
		for (int j = 1; j <= n; j++)
			if (dist[j] > dist[u] + distmap[u][j])
			{
				dist[j] = dist[u] + distmap[u][j];//������u���ڵ�dist 
				path[j] = u;//����¼��·�� 
			}
		if(visited[End]==1) break;//���յ�����·���ҵ�������ѭ��	
	}
	return dist[End]; 
}
void PushPath(int End)
{
	int before= path[End];//�Ƚ�path push��stack 
	while (before!=start) 
	{
		Stack.push(before);
		before = path[before];
	}
}
void PopPath() {
	cout << "Path:" << endl;
	cout << (char)('a' + start - 1) <<"->" ;
	while (Stack.size()!=0)//������pop��·�� 
	{
		cout <<(char)('a'+Stack.top()-1) << "->";
		Stack.pop();
	}
	cout << (char)('a' + End - 1);
}
int main()
{
	Init();
	cout <<"shortest distance is " <<Dijkstra(start,End) << endl;;//ִ��Dijkstra�㷨 
	PushPath(End);//��path push��stack
	PopPath();//��pop��·�� 
	return 0;
}

