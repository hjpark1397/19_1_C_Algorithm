#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap (type, x, y) do {type t = x; x = y; y = t; } while(0)
int count = 0;

void bubble(int a[],int n){
	int k=0;
	while(k<n-1){
		int j;
		int last = n-1;
		for(j=n-1;j>k;j--)
		if(a[j-1]>a[j]){
			swap(int, a[j-1], a[j])
			last = j;
		}
		k=last;
	}
	count++;
}

int main(void){
	srand((unsigned)time(NULL));
	clock t start, finish;
	double duration;
	int i, nx;
	int *x; //�迭�� ù��° ��ҿ� ���� ������
	
	puts("��������");
	printff("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for(i=0; i<nx; i++){
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	
	bubble(x, nx);
	
	start = clock();
	puts("������������ �����߽��ϴ�.");
	
	for(i=0; i<nx;i++)
		printf("x[%d]=%d\n", i, x[i]);
	
	free(x);
	
	
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("%f ���Դϴ�.\n", duration);
	printf("%d ȸ �۾��߽��ϴ�.", count);
	
	return 0;
}
