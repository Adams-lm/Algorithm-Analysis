#include<iostream>
#include<stdlib.h>
using namespace std;

int a[8] = { 5, 2, 4, 6, 1 ,7 ,8, 3 };


int Merge(int a[],int low, int mid, int high)// �ϲ�����
{
	int b[16];
	int j, k, h;
	j = low;
	h = mid + 1;
	k = low;
	while (j<=mid&&h<=high)	// �������������ݽ��бȽϣ����븨��������
	{
		if (a[j] < a[h])
			b[k++] = a[j++];
		else
			b[k++] = a[h++];
	}
	// ��ʣ������ݼ��뵽����������
	while (j <= mid)
	{
		b[k++] = a[j++];
	}
	while (h<=high)
	{
		b[k++] = a[h++];
	}
	for (k = low; k <= high; k++)// ��������������ݸ��Ƶ�ԭ����Ķ�Ӧλ����
	{
		a[k] = b[k];
	}
}

int MergeSort(int a[],int low,int high)	// �ݹ���麯��
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a,low, mid);
		MergeSort(a,mid + 1, high);
		Merge(a,low, mid, high);// ����Merge�������ϲ��������� 
	}
}
main()
{
	MergeSort(a,0, 7);
	for (int i = 0; i < 8; i++)
		cout << a[i] << ",";
}

