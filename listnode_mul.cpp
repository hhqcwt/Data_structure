#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_mul(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef * b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) printf("%d^%d + ", p->coef, p->expon);
	printf("\n");
}

void main() {

	int a[SIZE * 2], n[SIZE * 2];
	int i = 0, j = 0, least, tmp;
	ListType* list1, * list2, * list3;
	FILE* fp = NULL;

	fp = fopen("data04.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	while (!feof(fp))
	{
		fscanf(fp, "%d", &a[i]);
		fscanf(fp, "%d", &n[i]);
		i++;
	}

	for (i = 0; i < SIZE - 1; i++) {
		least = i;
		for (j = i + 1; j < SIZE; j++)
			if (n[j] > n[least])
				least = j;

		tmp = a[i];
		a[i] = a[least];
		a[least] = tmp;

		tmp = n[i];
		n[i] = n[least];
		n[least] = tmp;

	}

	for (i = SIZE; i < (SIZE * 2) - 1; i++) {
		least = i;
		for (j = i + 1; j < SIZE * 2; j++)
			if (n[j] > n[least])
				least = j;

		tmp = a[i];
		a[i] = a[least];
		a[least] = tmp;

		tmp = n[i];
		n[i] = n[least];
		n[least] = tmp;

	}

	printf("다항식1의 계수와 차수 출력\n");
	for (i = 0; i < SIZE; i++) {
		printf("a[%d] = %d, n[%d] = %d\n", i, a[i], i, n[i]);
	}
	printf("\n");

	printf("다항식2의 계수와 차수 출력\n");
	for (i = SIZE; i < (SIZE * 2); i++) {
		printf("a[%d] = %d, n[%d] = %d\n", i, a[i], i, n[i]);
	}
	printf("\n");

	list1 = create();
	list2 = create();
	list3 = create();

	for (int i = 0; i < SIZE; i++) {
		insert_last(list1, a[i], n[i]);
		//insert_last(list2, a[i+SIZE], n[i+SIZE]);
	}
	for (i = SIZE; i < (SIZE * 2); i++) {
		insert_last(list2, a[i], n[i]);
	}

	poly_mul(list1, list2, list3);
	printf("\n다항식1 출력\n");
	poly_print(list1);
	printf("\n다항식2 출력\n");
	poly_print(list2);
	printf("\n다항식3=다항식1 * 다항식2 출력\n");
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
}