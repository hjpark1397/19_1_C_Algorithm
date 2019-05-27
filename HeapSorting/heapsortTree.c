/* Q22 �� ����(���� ������ Ʈ���� ���) */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//���� ����

 
/*--- 2�� n ������ ���մϴ�. ---*/
static int pow2(int n)
{
   int k = 1;

   while (n--)
      k *= 2;
   return (k);
}

/*--- �� ��� ---*/
static void disp_heap(int a[], int n)
{
   int i, w, level;
   int height = 1;      /* Ʈ���� ���� */

   i = n;
   while (i /= 2)
      height++;//���̸� �ϳ� �����ش�. 

   i = 0;
   w = 1;
   for (level = 0; level < height; level++) {
      int k;
      printf("%*s", pow2(height - level) - 2, "");
      for (k = 0; k < w; k++) {
         printf("%02d", a[i++]);
         if (i >= n) goto Exit;
         printf("%*s", pow2(height - level + 1) - 2, "");
      }
      putchar('\n');

      printf("%*s", pow2(height - level) - 3, "");
      for (k = 0; k < w; k++) {
         if (2 * k + i     < n) printf("��");
         if (2 * k + i + 1 < n) printf("��");
         printf("%*s", pow2(height - level + 1) - 4, "");
      }
      putchar('\n');
      w *= 2;
   }
Exit:
   putchar('\n');
   putchar('\n');
}

/*--- a[left]��a[right]�� ������ ����ϴ�. ---*/
static void downheap(int a[], int left, int right)
{
   int temp = a[left];            /* ��Ʈ */
   int child;
   int parent;

   for (parent = left; parent < (right + 1) / 2; parent = child) {
      int cl = parent * 2 + 1;      /* ���� �ڽ� */
      int cr = cl + 1;            /* ������ �ڽ� */
      child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   /* ū ���� child�� �����մϴ�. */
      if (temp >= a[child])
         break;
      a[parent] = a[child];
   }
   a[parent] = temp;
}

/*--- �� ����---*/
void heapsort(int a[], int n)
{
   int i;

   puts("�迭�� ������ ����ϴ�.\n"); /*downheap �Լ��� ����Ͽ� �迭 a�� ������ �����.*/
   for (i = (n - 1) / 2; i >= 0; i--) {
      disp_heap(a, n);
      downheap(a, i, n - 1);
   }

   puts("���� �������� �����մϴ�.\n");/* ��Ʈ a[0]�� �ִ� ���� ū ���� ������ �迭 ������ ��ҿ� �ٲٰ� */
   for (i = n - 1; i > 0; i--) {      /* �迭�� ������ �κ��� �ٽ� ������ ����� ������ �ݺ��Ͽ� ���� ���� */
      swap(int, a[0], a[i]);
      disp_heap(a, n);
      downheap(a, 0, i - 1);
   }
}

int main(void)
{
   int i, nx;
   int *x;      

   puts("�� ����");
   printf("��ڼ� : ");
   scanf("%d", &nx);
   x = calloc(nx, sizeof(int));

   for (i = 0; i < nx; i++) {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
   }

   heapsort(x, nx);   

   puts("������������ �����߽��ϴ�.");//���� �� ���Ŀ� ���� �ǹ�����.. 
   for (i = 0; i < nx; i++)
      printf("x[%d] = %d\n", i, x[i]);

   free(x);

   return 0;
}
