#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=100;
int n,m,father[MAX];//��������������������ͨ�����ĸ��ڵ㣨���鼯�� 

struct Edge{
    int u,v,cost;
}t[MAX*MAX/2];// ������ͨ��Ȩͼ���ڽӾ���

int cmp(Edge &a,Edge &b){//����Ȩֵ���� 
    return a.cost<b.cost;
}
int find(int x){//�ж���ͨ��֧ 
    return (x==father[x])?x:father[x]=find(father[x]);
}
void merge(int x,int y){//����ͬһ��ͨ��֧ 
    father[find(x)]=find(y);
}
int Kruskal()
{	    
		cout<<"Kruskal:"<<endl;
        sort(t+1, t+m+1, cmp);//���� 
        for(int i=1;i<=n;i++) father[i]=i;//���鼯��ʼ��Ϊ���� 
        int total=0;//��ѡȡ�ı��� 
        int sumweight=0;//Ȩ�غ� 
        for(int i=1;i<=m;i++){
        	if(total==n-1) break; //n-1ʱ��ʽ��С������  
            int x=t[i].u,y=t[i].v;
            if(find(x)!=find(y)){//������ͬһ��ͨ��֧ 
            	cout<<x<<"--"<<y<<":"<<t[i].cost<<endl; 
                sumweight+=t[i].cost;
                merge(x,y);//����ͬһ��ͨ��֧ 
                total++;
            }
        }
        return sumweight;//����Ȩ�غ� 
}
int main(){		
        int x,y,cost;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>cost;
            t[i].u=x;t[i].v=y;t[i].cost=cost;
        }
        cout<<"the minimum sumweight is "<<Kruskal()<<endl;
        
}

