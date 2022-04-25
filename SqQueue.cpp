#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define  MaxSize 10
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

bool Full(SqQueue &Q){
   return Q.front == (Q.rear+1)%MaxSize;
}

bool EnQueue(SqQueue &Q,int x){
    if(Full(Q))return false;
    Q.data[Q.rear] =x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

bool OutQueue(SqQueue &Q, int &x) {
    if (Empty(Q))return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
}