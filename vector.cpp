#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int original[MAX][MAX];		// 오리지널 행렬
	int transpose[MAX][MAX];	// 전치 행렬
	FILE* fp;
	int tempNumber, nOfLine = 0, nRow = 0;
	int i, j;
	char tempChar = '\0';

	fp = fopen("data2.txt", "r");
	if (fp == NULL)
	{
		printf("File Not Found");
		return 0;
	}

	// vector initialize
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			original[i][j] = -1;
			transpose[i][j] = -1;
		}
	}

	// count n of lines
	while (!feof(fp))
	{
		if (tempChar == '\n')
		{
			break;
		}
		fscanf(fp, "%d%c", &tempNumber, &tempChar);
		nOfLine++;
	}

	// reset to first part of file
	rewind(fp);

	// read-in actual data
	while (!feof(fp))
	{
		for (i = 0; i < nOfLine; i++)
		{
			fscanf(fp, "%d", &original[nRow][i]);
		}
		nRow++;
	}

	// display original vector
	printf("Orginal Matrix\n");

	for (i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nOfLine; j++)
		{
			printf("%d\t", original[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nOfLine; j++)
		{
			transpose[j][i] = original[i][j];
		}
	}

	// transpose vector
	printf("transpose Matrix\n");

	for (i = 0; i < nOfLine; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			printf("%d\t", transpose[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
}
