#include <iostream>
#include "pch.h"
#include <stdio.h>

#define MAX 100

typedef struct {
	int nPriority;
}QueueObject;

QueueObject queue[MAX];
int front, rear;

void init() { front = rear = 0; }

int isEmpty() { return (front == rear); }

int isFull() { return ((rear + 1) % MAX == front); }

void addq(int item, int nItems) {
	int j;
	if (isFull()) { printf("queue is full\n"); };
	if (nItems == 0)
		queue[nItems++].nPriority = item;
	else
	{
		for(j=nItems-1;j>=0;j--){
			if (item < queue[j].nPriority)
				queue[j + 1].nPriority = queue[j].nPriority;
			else
				break; 
		}
		queue[j + 1].nPriority = item;
	}

	rear = (rear + 1) % MAX;
	//queue[rear]=item;


}

QueueObject deleteq() {
	if (isEmpty()) { printf("queue is empty\n"); }
	else{
		front = (front + 1) % MAX;
		return queue[front];
	}
}

void main() {
	FILE* fp;
	int temp;
	QueueObject sttemp;
	int i, nCount;

	fp = fopen("data09_1.txt", "r");
	nCount = 1;

	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
		addq(temp, nCount);
		nCount++;
	}

	for (i = 0; i < nCount - 1; i++) {
		sttemp = deleteq();
		printf("%d ->", sttemp.nPriority);

	}
	printf("\n");
	//printf("front=%d rear=%d\n",front,rear);
}