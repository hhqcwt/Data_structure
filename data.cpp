#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	FILE* fp;
	int nCount = 0, data, i = 0;
	int MaxIndex = 0, MinIndex = 0;
	fp = fopen("data3.txt", "r");
	int* pData;

	if (fp == NULL)
	{
		printf("Fail");
		return 0;
	}

	// read-in number of numbers
	while (!feof(fp))
	{
		fscanf(fp, "%d", &data);
		nCount++;
	}

	// memory allocation
	pData = (int*)malloc(sizeof(int) * nCount); // 4 bytes * 100; = 400

	// read in actual data
	rewind(fp);

	while (!feof(fp))
	{
		fscanf(fp, "%d", &pData[i]);
		i++;
	}

	printf("Input Array : \n");
	for (int n = 0; n < nCount; n++)
	{
		printf("%d\t", pData[n]);

		if (pData[n] > pData[MaxIndex])
		{
			MaxIndex = n;
		}
		if (pData[n] < pData[MinIndex])
		{
			MinIndex = n;
		}

	}
	printf("\n");
	printf("Max : %d\n", pData[MaxIndex]);
	printf("Min : %d\n", pData[MinIndex]);

	fclose(fp);
	free(pData);

	return 0;
}
