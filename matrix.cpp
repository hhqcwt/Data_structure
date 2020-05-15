#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 4
#define MAX_COLS 4

typedef struct element {
    int row;   //��
    int col;   //��
    int value;  //��
}ELEMENT;

int main()
{
    FILE* fp = NULL;

    int matrix_a[MAX_ROWS][MAX_COLS]; //���A
    int matrix_b[MAX_ROWS][MAX_COLS]; //���B
    int cnt_a, cnt_b = 0; //0�� �ƴ� ���� ����

    fp = fopen("data5.txt", "r");
    if (fp == NULL)
        printf("���� ���� ����\n");
    else
        printf("���� ���� ����\n");
    while (!feof(fp))
    {
        for (int i = 0; i < MAX_COLS; i++)
        {
            for (int j = 0; j < MAX_ROWS; j++)
            {
                fscanf(fp, "%d", &matrix_a[i][j]);
            }
        }
        for (int i = 0; i < MAX_COLS; i++)
        {
            for (int j = 0; j < MAX_ROWS; j++)
            {
                fscanf(fp, "%d", &matrix_b[i][j]);
            }
        }
    }

    // �迭 ������ 0�� �ƴ� ���� ������ ����
    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_ROWS; j++)
        {
            if ((matrix_a[i][j]) != 0)
                cnt_a++;
            if ((matrix_b[i][j]) != 0)
                cnt_b++;
        }
    }
    //���A�� ���B �����Ҵ�
    ELEMENT* CompMatrix_a = (ELEMENT*)malloc(sizeof(ELEMENT) * (cnt_a));
    ELEMENT* CompMatrix_b = (ELEMENT*)malloc(sizeof(ELEMENT) * (cnt_b));

    //�����ϱ�
    Compress(matrix_a, MAX_COLS, MAX_ROWS, cnt_a, CompMatrix_a);
    Compress(matrix_b, MAX_COLS, MAX_ROWS, cnt_b, CompMatrix_b);
    fclose(fp);
    return 0;
}