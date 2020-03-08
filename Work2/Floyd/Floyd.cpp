#include<iostream>
#define MAX 1000//顶点数 
#define INF 0x3f3f3f3f//无穷大 
using namespace std;
int distmap[MAX][MAX];//图各点距离矩阵
int n; 
void Init()//初始化距离矩阵 
{	
	cout<<"请输入顶点数："<<endl; 
	cin>>n;//输入顶点数n 
	cout<<"请输入"<<n<<"*"<<n<<"矩阵："<<endl; 
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
		{
			cin>>distmap[i][j];
            if(distmap[i][j]==0&&i!=j)//0即为无穷大，忽略到自身距离 
            	distmap[i][j]=INF;
		}

}
void Floyd()
{
	cout<<"Floyd："<<endl; 
    for(int k=0; k<n; k++)//中转点遍历 
        for(int i=0; i<n; i++)//起点 
            for(int j=0; j<n; j++)//终点 
	                distmap[i][j]=min(distmap[i][j],distmap[i][k]+distmap[k][j]);//更新最短距离 
}
void Print()//打印最短距离矩阵 
{
  for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j&&distmap[i][j]==INF)
                cout<<"∞ ";
            else
                cout<<distmap[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	Init();//输入顶点数n以及n*n矩阵 
    Floyd();//Floyd算法 
	Print();//打印最短距离矩阵 
    return 0;
}

