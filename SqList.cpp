#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define  MaxSize 10

typedef struct SqList {
    int data[MaxSize];
    int length;
} SqList;

void InitSqList(SqList &L) {
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;
    }
    L.length = 0;
}

int InsertSqList(SqList &L,int i,int e){
    if(i>L.length+1||i<1) return 0;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return 1;
}

void print(SqList &l){
    for(int i=0;i<l.length;i++){
        printf("  %d",l.data[i]);
    }
}

int DeleteList(SqList &L,int i){
    if(i>L.length||i<1) return 0;
    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return 1;
}

int main() {
    SqList l;
    InitSqList(l);

    l.data[0] = 1;
    l.data[1] = 2;
    l.data[2] = 3,
    l.length = 3;
    int n ;
    scanf("%d",&n);
    InsertSqList(l,2,n);

    int delete_i ;
    scanf("%d",&delete_i);
    print(l);
    printf(" \n");
    if(DeleteList(l,delete_i)==0){
        printf("false");
    }else {
        print(l);
    }
}