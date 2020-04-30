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
		if ((i % 2) == 1)	// ¦��
			sum += data[i] * 3;
		else                // Ȧ��
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
			printf("ISBN�ڵ�� 13�ڸ��Դϴ�.");
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
		printf("�� ��ȿ�� ISBN�Դϴ�.\n");
	}
	else
	{
		printf("�� ��ȿ���� ���� ISBN�Դϴ�\n");
	}

	return TRUE;
}
