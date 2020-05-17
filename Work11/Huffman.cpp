#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int weight;//Ȩ��
	int lchild, rchild, parent;//˫�׺����Һ����±�
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;
HuffmanCode HC;
HuffmanTree HT;
int s1, s2;
void SelectMin(HuffmanTree tree, int n) { //�ҳ�Ȩֵ��С��������
	int min = 1;//�����ʱ��Сֵ
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0) {//�ҳ�һ����ʱ����Сֵ
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && tree[i].weight < tree[min].weight) {//�ҳ���һ����Сֵ
			min = i;
		}
	}
	s1 = min;
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && i != s1) {//�ҳ�һ����ʱ����Сֵ
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && tree[i].weight < tree[min].weight && i != s1) {//�ҳ��ڶ�����Сֵ
			min = i;
		}
	}
	s2 = min;
}
void Huffman(HuffmanTree tree, int* w, int n) {//����������
	int m = 2 * n - 1;//���������Ľڵ���
	tree = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (int i = 1; i <= m; i++) {//��ʼ����
		tree[i].lchild = 0;
		tree[i].rchild = 0;
		tree[i].parent = 0;
		if (i <= n) {//����Ȩֵ
			tree[i].weight = w[i];
		}
		else {
			tree[i].weight = 0;
		}
	}
	for (int i = n + 1; i <= m; i++) {
		SelectMin(tree, i - 1);
		tree[s1].parent = tree[s2].parent =i;
		tree[i].lchild = s1,tree[i].rchild = s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight;//i��ȨֵΪs1��s2�ĺ�
	}
	HC = (HuffmanCode)malloc((n + 1) * (sizeof(char*)));//���n������������
	char* cd;
	cd = (char*)malloc(n * sizeof(char));//�ݴ����������
	cd[n - 1] = '\0';//���������
	int start;
	for (int i = 1; i <= n; i++) {
		start = n - 1;//��ʼ��
		for (int j = i, f = tree[i].parent; f != 0; j = f, f = tree[f].parent) { //���������������
			if (tree[f].lchild == j) cd[--start] = '0'; //����Ϊ0
			else cd[--start] = '1';//����Ϊ1
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);//�����ַ��Ĺ��������븳��HC��
	}
	free(cd);
}
int main() {
	int n = 8;
	int w[100] = { 0,8,6,4,1,2,3,3,1 };//���ÿ���ַ���Ȩֵ
	Huffman(HT, w, n);
	for (int i = 1; i <= n; i++) {//���ÿ���ַ��Ĺ���������
		printf("%d:%s\n", w[i],HC[i]);
	}
}
