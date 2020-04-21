#include <stdio.h>
//막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다.
void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1) {
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판%d을 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
void main()
{
	int n;
	printf("디스크의 수를 입력하시오: ");
	scanf("%d", &n);
	hanoi_tower(n + 1, 'A', 'B', 'C');
}