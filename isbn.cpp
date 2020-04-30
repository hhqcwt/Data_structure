#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

int ValidISBN(int data[])
{
	int sum = 0;

	// a+3*b+c+3*d.... 
	for (int i = 0; i < 13; i++)
	{
		if ((i % 2) == 1)	// 짝수
			sum += data[i] * 3;
		else                // 홀수
			sum += data[i]; // sum = sum + data[i];
	}

	if ((sum % 10) == 0)
		return TRUE;
	else
		return FALSE;
}

int main()
{
	int ISBN[13];
	int n = 0;
	int isValid = 0;
	FILE* fp;

	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("File Not Found\n");
		return FALSE;
	}

	while (!feof(fp))
	{
		if (n > 13)
		{
			printf("ISBN코드는 13자리입니다.");
			return FALSE;
		}

		fscanf(fp, "%d", &ISBN[n]);
		n++;
	}

	fclose(fp);

	isValid = ValidISBN(ISBN);

	for (int i = 0; i < 13; i++)
	{
		printf("%d", ISBN[i]);
	}

	if (isValid == 1)
	{
		printf("은 유효한 ISBN입니다.\n");
	}
	else
	{
		printf("은 유효하지 않은 ISBN입니다\n");
	}

	return TRUE;
}
