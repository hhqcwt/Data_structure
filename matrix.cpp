#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 4
#define MAX_COLS 4

typedef struct element {
    int row;   //열
    int col;   //행
    int value;  //값
}ELEMENT;

int main()
{
    FILE* fp = NULL;

    int matrix_a[MAX_ROWS][MAX_COLS]; //행렬A
    int matrix_b[MAX_ROWS][MAX_COLS]; //행렬B
    int cnt_a, cnt_b = 0; //0이 아닌 값의 개수

    fp = fopen("data5.txt", "r");
    if (fp == NULL)
        printf("파일 열기 실패\n");
    else
        printf("파일 열기 성공\n");
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

    // 배열 내에서 0이 아닌 값의 개수를 개산
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
    //행렬A와 행렬B 동적할당
    ELEMENT* CompMatrix_a = (ELEMENT*)malloc(sizeof(ELEMENT) * (cnt_a));
    ELEMENT* CompMatrix_b = (ELEMENT*)malloc(sizeof(ELEMENT) * (cnt_b));

    //압축하기
    Compress(matrix_a, MAX_COLS, MAX_ROWS, cnt_a, CompMatrix_a);
    Compress(matrix_b, MAX_COLS, MAX_ROWS, cnt_b, CompMatrix_b);
    fclose(fp);
    return 0;
}