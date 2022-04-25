#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

typedef struct LinkNode {
    int data;
    LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} *LinkQueue;

void InitQueue(LinkQueue &Q) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->next = NULL;
    Q->front = Q->rear = s;
}

void InitQueue2(LinkQueue &Q) {
    Q->front = Q->rear = NULL;
}

bool Empty(LinkQueue &Q) {
    return Q->rear == Q->front;
}

bool Empty2(LinkQueue &Q) {
    return Q->front == NULL;
}

bool EnQueue(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

//不带头节点入队需要处理空队时入队的情况
bool EnQueue2(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;

    if (Empty2(Q)) {
        Q->front = s;
    } else {
        Q->rear->next = s;
    }
    Q->rear = s;
    return true;
}

//出队注意是否出队的是最后一个节点，如果是需要处理成空队列
bool DeQueue(LinkQueue &Q, int &x) {
    if (Empty(Q))return false;
    LinkNode *p = Q->front->next;
    x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}

bool DeQueue2(LinkQueue &Q, int &x) {
    if (Empty2(Q))return true;
    LinkNode *p = Q->front;
    x = p->data;
    Q->front = p->next;
    if (Q->rear == p) {
        Q->rear = NULL;
    }
    free(p);
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
}