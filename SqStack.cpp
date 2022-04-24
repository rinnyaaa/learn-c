#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define  MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

//S.top = -1; top指针指向当前栈顶。
//S.top = 0;top指针指向下一个将要入栈的位置。

void InitStack(SqStack &S) {
//    S.top = -1;
    S.top = 0;
}

bool Empty(SqStack &S) {
//    S.top == -1;
    S.top == 0;
}

bool Full(SqStack &S) {
    S.top == MaxSize;
}

bool Push(SqStack &S, int x) {
    if (Full(S))return false;
    S.data[S.top++] = x;
    return true;
}

bool Pop(SqStack &S, int &x) {
    if (Empty(S))return false;
    x = S.data[--S.top];
}

int main() {
    SqStack S;
    InitStack(S);
    int x;
    for(int i =0;i<3;i++){
        scanf("%d",&x);
        Push(S,x);
    }
    int y;
    for(int j =0;j<3;j++){
        Pop(S,y);
        printf("%2d",y);
    }
    printf("\n");
}