#include <iostream>
#include <stdlib.h>

typedef struct element
{
    char name[20];
    double kor;
    double math;
    double com;
    double total;
};

typedef struct myname
{
    char last_name[20];
    char first_name[20];
}myname;

typedef struct ListNode
{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* create_node(element data, ListNode* link)
{
    ListNode* new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL)
    {
        printf("메모리 할당 에러\n");
        exit(1);
    }

    new_node->data = data;
    new_node->link = link;

    return new_node;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
    if (*phead == NULL)
    {
        new_node->link = NULL;
        *phead = new_node;
    }
    else if (p == NULL)
    {
        new_node->link = *phead;
        *phead = new_node;
    }
    else
    {
        new_node->link = p->link;
        p->link = new_node;
    }

}

void display(ListNode* head)
{
    ListNode* p = head;

    while (p != NULL)
    {
        printf("%s %0.1lf %0.1lf %0.1lf %0.1lf\n", p->data.name, p->data.kor, p->data.math, p->data.com, p->data.total);
        p = p->link;
    }
}

int main()
{
    FILE* fp;
    element tmp;
    ListNode* list = NULL;

    fp = fopen("score.txt", "r");

    if (fp == NULL)
    {
        printf("파일 못 찾음");
        return 0;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s %lf %lf %lf", &tmp.name, &tmp.kor, &tmp.math, &tmp.com);
        tmp.total = tmp.kor + tmp.math + tmp.com;

        insert_node(&list, NULL, create_node(tmp, NULL));
    }
    display(list);
    fclose(fp);
    return 0;
}