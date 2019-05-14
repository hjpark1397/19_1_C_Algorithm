#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int count = 0;

void bubble(int a[], int n)//첫번째 알고리즘 
{
	int i,j;
	for(i=0;i<n-1; i++)
		for(j=n-1; j>i; j--)
		if(a[j-1]>a[j]){
			swap(int, a[j-1],a[j]);
	}
	count++;
}	

int main(void)
{
	
	clock_t start, finish;
	double duration;
//	srand((unsigned)time(NULL));
	int i, nx;
	int x[10000];
	start = clock();
	puts("버블 정렬\n");
	printf("1번째[기본] 알고리즘 사용\n") ;
	printf("요소 개수  : 10,000\n"); 
	nx=10000;
int k;
for(k=3; k<=10000; k+=2){
	srand(k);
	for (i = 0; i < nx; i++) {
	
		x[i]=rand()%10000+1;
	}
//	start = clock();
	bubble(x, nx);	
	finish = clock();
	
	duration = (double) (finish - start) / CLOCKS_PER_SEC;
	printf("seed %d은(는)  %f 초입니다. \n", k,duration); 
	printf("변경 횟수는 %d 입니다.", count);

}
	return 0;
}


