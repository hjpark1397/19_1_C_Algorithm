#include <stdio.h>
/*�ϳ����� ž*/
void move(int no, int x, int y){
	if(no > 1)
		move(no - 1, 6 - x - y, y); //�׷��� ���� ��տ��� �߰� ������� 
	printf("���� [%d]��(��) %d ��տ��� %d ������� �ű�\n", no, x, y); //�ٴ� ������ ��ǥ ������� 

	if(no > 1)
		move(no - 1, 6 - x - y, y );
}
int main(void){
	int n; /*������ ����*/
	printf("�ϳ����� ž\n ���� ���� : ");
	scanf("%d", &n);
	move(n, 1, 3);
	
	return 0;
}
