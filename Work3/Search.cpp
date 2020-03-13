#include<iostream>
using namespace std;
int BinarySearch(int T[], int value, int n)
{
	cout<<"BinarySearch:"<<endl; 
	int left=0,right=n-1,mid; 
	while(left<=right)
	{
		mid=(left+right)/2;//�е� 
		if(T[mid]==value)//�����return 
			return mid+1;
		if(T[mid]>value)//̫�� 
		right=mid-1;//right�������е� 
		else//̫С��left�������е� 
		left=mid+1;
	}
	return 0;//û���ҵ�����0 
}
int InsertionSearch(int T[], int value,int n)
{
	cout<<"InsertionSearch:"<<endl; 
	int left=0,right=n-1,mid; 
	while(left<=right)
	{    
		int mid = left+(value-T[left])/(T[right]-T[left])*(right-left);
	    if(T[mid]==value)//�����return 
    	    return mid+1;
    	if(T[mid]>value)//̫�� 
		right=mid-1;//right�������е� 
		else//̫С��left�������е� 
		left=mid+1;
	}
	return 0;//û���ҵ�����0 
}
int main(){
	int T[]={1,3,5,6,8,10,15,23,43,55,62,67,68,89};
	int n=sizeof(T)/sizeof(int);//���鳤�� 
	cout<<BinarySearch(T,15,n)<<endl;//���ֲ��� 
	cout<<InsertionSearch(T,15,n)<<endl;//��ֵ���� 
}
