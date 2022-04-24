#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define  MaxSize 10
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
    p = (LinkNode *) malloc(sizeof (LinkNode));
    p->data = x;
    p->next=S->next;
    S->next=p;
}

bool Pop(LinkStack &S, int &x) {
    if (Empty(S))return false;
    LinkNode *p;
    p=S->next;
    S->next=p->next;
    x=p->data;
    free(p);
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
}