#include <stdio.h>
//���� from�� �׿��ִ� n���� ������ ���� tmp�� ����Ͽ� ���� to�� �ű��.
void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("����%d�� %c���� %c�� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
void main()
{
	int n;
	printf("��ũ�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	hanoi_tower(n + 1, 'A', 'B', 'C');
}