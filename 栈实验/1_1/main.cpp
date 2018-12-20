#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define List_init_size 100
typedef struct
{
    int *base;
    int *top;
    int ListSize;
} SqStack;
/**********
����������ʼ��ջ
������SqStack ����n
���أ�void
**********/
void Init_Stack(SqStack &S,int n)
{
    S.base=(int *)malloc(n*sizeof(int));
    if(!S.base)
        printf("ջ��ʼ��ʧ��\n");
    S.top=S.base;
    S.ListSize=n;
}
/**********
�����������ջ
������SqStack
���أ�OK
**********/
int clear_Stack(SqStack &S)
{
    while(S.top>S.base)
    {
        S.top--;
    }
    printf("ջ�Ѿ����\n");
    return OK;
}
/**********
���������ݻ�ջ
������SqStack
���أ�OK
**********/
int destory_Stack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.ListSize=0;
    printf("ջ�Ѿ��ݻ�\n");
    return OK;
}
/**********
������������ջ
������SqStack x
���أ�OK
**********/
int push(SqStack &S,int x)
{
    if(S.top-S.base>=S.ListSize)
    {
        printf("ջ�Ѿ�����\n");
        return OVERFLOW;
    }
    *(S.top)=x;
    S.top++;
    return OK;
}
/**********
����������ջ
������SqStack x
���أ�OK
**********/
int Pop(SqStack &S,int &x)
{
    if(S.base==S.top)
    {
        printf("ջ�Ѿ�����\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}
int printf_Stack(SqStack &S)
{
    int * i=S.base;
    if(S.base==S.top)
    {
        printf("��\n");
        return OK;
    }
    while(i<S.top-1)
    {
        printf("%d ",*i);
        i++;
    }
    printf("%d\n",*i);
    return 0;
}
void printf_menu(void)
{
    printf("1����ʼ��ջ\n");
    printf("2������ջ\n");
    printf("3����ջ\n");
    printf("4�����ջ\n");
    printf("5����ӡջ��Ԫ��\n");
    printf("6������ջ\n");
    printf("7���˳�\n");
}
int main()
{
    SqStack S;
    int n,i;
    printf_menu();
    scanf("%d",&i);
    while(i!=7)
    {
        switch (i)
        {
        case 1:
        {
            printf("������ջ�ĳ���\n");
            scanf("%d",&n);
            Init_Stack(S,n);
            break;
        }
        case 2:
        {
            printf("������Ҫ��ջ����:\n");
            scanf("%d",&n);
            push(S,n);
            break;
        }
        case 3:
        {
            Pop(S,n);
            printf("��ջԪ����%d\n",n);
            break;
        }
        case 4:
        {
            clear_Stack(S);
            break;
        }
        case 5:
        {
            printf_Stack(S);
            break;
        }
        case 6:
            destory_Stack(S);
            break;
        }
        printf_menu();
        scanf("%d",&i);
    }
}
