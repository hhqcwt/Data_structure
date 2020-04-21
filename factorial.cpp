#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int maze[8][10] =
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
};

int f[8][10] = { 0 };

void find(int i, int j)
{
	// base condition
	// 동 서 남 북
	// 1. inside grid(map)?
	// 2. 이동하고자 하는 곳이 벽인가?
	// 3. 이동하고자 하는 곳이 길인가?

	f[i][j] = 1; // 지난온 길은 1로 토글
	printf("(%d, %d)\n", i, j);

	// 동쪽으로 이동 case
	if (j + 1 < 10 && maze[i][j + 1] != 1 && f[i][j + 1] == 0)
		find(i, j + 1);
	// 서쪽으로 이동 case
	if (j - 1 >= 0 && maze[i][j - 1] != 1 && f[i][j - 1] == 0)
		find(i, j - 1);
	// 남쪽으로 이동 case
	if (i + 1 < 8 && maze[i + 1][j] != 1 && f[i + 1][j] == 0)
		find(i + 1, j);
	// 북쪽으로 이동 case
	if (i - 1 >= 0 && maze[i - 1][j] != 1 && f[i - 1][j] == 0)
		find(i - 1, j);
}

int factorial(int n)
{
	// base return condition
	// factorial(5) = f(5) -> f(4) -> f(3) -> f(2) -> f(1) -> f(0) return
	if (n == 0)
		return 1;
	else
		// n = 5 가정
		// return 5 * factorial(4)
		//            return 4 * factorial(3)
		//                       return 3 * factorial(2)
		//                                  return 2 * factorial(1)
		//                                             return 1 * factorial(0)
		//                                                        if (n == 0) return 1;
		//                                             return 1 * 1; 
		//                                  return 2 * 1;
		//                       return 3 * 2 * 1;
		//            return 4 * 3 * 2 * 1;
		//  return 5 * 4 * 3 * 2 * 1;

		return n * factorial(n - 1);



}

int power(int x, int n)
{
	// base condition
	// 2^3 = 2 * power(2, 2) => 2 * power(2, 1) => 2 * power(2, 0)
	// 2^3 = 2 * 2 * 2

	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1); // x * x * x
}


int fibonacci(int n)
{
	// n = f(n-1) + f(n-2)
	// 1, 1, 2, 3, 5, ...
	// base condition
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int strLength(char* str)
{
	// base condition
	// "Hello"
	// \0
	if (*str == '\0')
		return 0;
	else
		// 1st call : hello : 1 + strLength("ello");
		// 2nd call : ello : 1 + strLength("llo");
		// 3rd call : llo : 1 + strLength("lo");
		// 4th call : lo : 1 + strLength("o");
		// 5th call : o : 1 + strLength("\0")
		// 5th call : \0 <--------------------------- base condition

		return 1 + strLength(str + 1); // str[0] str[1] str[2] ...

}

void printStr(char* str)
{
	// base condition
	if (*str == '\0')
		return;
	else
	{
		printf("%c", *str);
		printStr(str + 1);
	}
}

void printReverseStr(char* str)
{
	// base condition
	if (*str == '\0')
		return;
	else
	{
		printReverseStr(str + 1);
		printf("%c", *str);
	}
}

int main()
{
	char str[] = "Hello";

	printf("Factorial : %d\n", factorial(5));

	printf("Power : %d\n", power(2, 10));

	printf("Fibonacci : %d\n", fibonacci(10));

	printf("String Length : %d\n", strLength(str));

	printf("String Print : ");
	printStr(str);
	printf("\n");

	printf("String Reverse Print : ");
	printReverseStr(str);
	printf("\n");

	find(1, 0);

	return 0;
}
