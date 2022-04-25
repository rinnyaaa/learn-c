#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define  MaxSize 5
typedef struct LinkNode {
    int data;
    LinkNode *next;
} LinkNode, *LinkStack;

void InitStack(LinkStack &S) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->next = NULL;
}

bool Empty(LinkStack &S) {
    S->next == NULL;
}

bool Push(LinkStack &S, int x) {
    LinkNode *p;
    p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = x;
    p->next = S->next;
    S->next = p;
}

bool Pop(LinkStack &S, int &x) {
    if (Empty(S))return false;
    LinkNode *p;
    p = S->next;
    S->next = p->next;
    x = p->data;
    free(p);
}

typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

bool Empty(SqQueue &Q) {
    return Q.rear == Q.front;
}

bool Full(SqQueue &Q) {
    return Q.front == (Q.rear + 1) % MaxSize;
}

bool EnQueue(SqQueue &Q, int x) {
    if (Full(Q))return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool OutQueue(SqQueue &Q, int &x) {
    if (Empty(Q))return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}


int main() {
    LinkStack S;
    InitStack(S);
    int x;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &x);
        Push(S, x);
    }
    int y;
    for (int j = 0; j < 3; j++) {
        Pop(S, y);
        printf("%2d", y);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    int z;
    for (int k = 0; k < MaxSize; k++) {
        scanf("%d", &z);
        if (EnQueue(Q, z) == false) printf("false\n");
    }

    for (int k = 0; k < MaxSize - 1; k++) {
        OutQueue(Q, z);
        printf("%2d", z);
    }
    return 0;
}