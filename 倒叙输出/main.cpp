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
������SqStack
���أ�OK OVERFLOW
**********/
int Init_Stack(SqStack &S)
{
    S.base=(int *)malloc(List_init_size*sizeof(int));
    if(!S.base)
    {
        printf("ջ��ʼ��ʧ��\n");
        return OVERFLOW;
    }
    S.top=S.base;
    S.ListSize=List_init_size;
    return OK;
}
/**********
������������
������SqStack
���أ�OK OVERFLOW
**********/
int Inputs_SqStack(SqStack &S)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        *(S.top)=n;
        S.top++;
        if((S.top-S.base)>=S.ListSize)
        {
            printf("��ջ\n");
            return OVERFLOW;
        }
    }
    return OK;
}
/**********
���������������
������SqStack
���أ�OK OVERFLOW
**********/
int print_SqStack(SqStack &S)
{
    int *p;
    for(p=S.top-1 ; p>=S.base+1; p--)
    {
        printf("%d ",*p);
    }
    printf("%d\n",*(p));
    return OK;
}
int main()
{
    SqStack S;
    Init_Stack(S);
    Inputs_SqStack(S);
    print_SqStack(S);
}
