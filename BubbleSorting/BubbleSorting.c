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
	int *x; //배열의 첫번째 요소에 대한 포인터
	
	puts("버블정렬");
	printff("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for(i=0; i<nx; i++){
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	
	bubble(x, nx);
	
	start = clock();
	puts("오름차순으로 정렬했습니다.");
	
	for(i=0; i<nx;i++)
		printf("x[%d]=%d\n", i, x[i]);
	
	free(x);
	
	
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("%f 초입니다.\n", duration);
	printf("%d 회 작업했습니다.", count);
	
	return 0;
}
