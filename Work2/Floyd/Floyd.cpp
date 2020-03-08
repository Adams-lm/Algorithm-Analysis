#include<iostream>
#define MAX 1000//������ 
#define INF 0x3f3f3f3f//����� 
using namespace std;
int distmap[MAX][MAX];//ͼ����������
int n; 
void Init()//��ʼ��������� 
{	
	cout<<"�����붥������"<<endl; 
	cin>>n;//���붥����n 
	cout<<"������"<<n<<"*"<<n<<"����"<<endl; 
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
		{
			cin>>distmap[i][j];
            if(distmap[i][j]==0&&i!=j)//0��Ϊ����󣬺��Ե�������� 
            	distmap[i][j]=INF;
		}

}
void Floyd()
{
	cout<<"Floyd��"<<endl; 
    for(int k=0; k<n; k++)//��ת����� 
        for(int i=0; i<n; i++)//��� 
            for(int j=0; j<n; j++)//�յ� 
	                distmap[i][j]=min(distmap[i][j],distmap[i][k]+distmap[k][j]);//������̾��� 
}
void Print()//��ӡ��̾������ 
{
  for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j&&distmap[i][j]==INF)
                cout<<"�� ";
            else
                cout<<distmap[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	Init();//���붥����n�Լ�n*n���� 
    Floyd();//Floyd�㷨 
	Print();//��ӡ��̾������ 
    return 0;
}

