#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define List_init_size 100
#define elem int
typedef struct
{
    elem *base1;
    elem *top1;
    elem *base2;
    elem *top2;
    int List_size;
} Dul_SqStack;
/*******
���ܣ���ʼ��ջ
������ջ
********/
int Init_SqStack(Dul_SqStack &S)
{
    S.base1=(elem *)malloc(List_init_size*sizeof(elem));
    if(!S.base1)
        return OVERFLOW;
    S.top1=S.base1;
    S.base2=&S.base1[List_init_size-1];
    S.top2=S.base2;
    S.List_size=List_init_size;
    return OK;
}
/*******
���ܣ�ѹ��ջ
������ջ��ѹ���ֵ��ѹ���ջ
*******/
int push(Dul_SqStack &S,int num,int mode)
{
    if(mode==1)
    {
        if(S.top1-1==S.top2) //��ջ
        {
            printf("��ջ\n");
            return OVERFLOW;
        }
        *S.top1=num;
        S.top1++;
    }
    else if(mode==2)
    {
        if(S.top1-1==S.top2) //��ջ
        {
            printf("��ջ\n");
            return OVERFLOW;
        }
        *S.top2=num;
        S.top2--;
    }
    else
        return ERROR;
}
/*****
��ջ
******/
int pop(Dul_SqStack &S,int &num,int mode)
{
    if(mode==1)
    {
        if(S.base1==S.top1)
            return 0;
        S.top1--;
        num=*S.top1;
    }
    else if(mode==2)
    {
        if(S.base2==S.top2)
            return 0;
        S.top2++;
        num=*S.top2;
    }
    else
        return ERROR;
}
/*****************
���ܣ����ջ
������ջ����յ�ջ
*****************/
int clear_Stack(Dul_SqStack &S,int mode)
{
    if(mode==1)
    {
        S.top1=S.base1;
    }
    else if(mode==2)
    {
        S.top2=S.base2;
    }
    else
        return ERROR;
}
/***************
���ջ
****************/
int printf_Stack(Dul_SqStack &S,int mode)
{
    elem *q;
    if(mode==1)
    {
        q=S.base1;
        for(q; q<S.top1-1; q++)
            printf("%d ",*q);
        printf("%d\n",*q);
    }
    else if(mode==2)
    {
        q=S.base2;
        for(q; q>S.top2+1; q--)
            printf("%d ",*q);
        printf("%d\n",*q);
    }
    else
        return ERROR;
}
int main()
{
    int n;
    Dul_SqStack S;
    Init_SqStack(S);
    printf("����ջ1Ԫ�أ���EOF����\n");
    while(scanf("%d",&n)!=EOF)
    {
        push(S,n,1);
    }
    printf("����ջ2Ԫ�أ���EOF����\n");
    while(scanf("%d",&n)!=EOF)
    {
        push(S,n,2);
    }
    printf_Stack(S,1);
    printf_Stack(S,2);
    pop(S,n,1);
    printf_Stack(S,1);
    printf("%d\n",n);
    pop(S,n,2);
    printf_Stack(S,2);
    printf("%d\n",n);
}
