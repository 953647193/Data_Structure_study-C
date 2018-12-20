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
int destory_stack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.ListSize=0;
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

        return 0;
    }
    x=*(--S.top);
    return OK;
}
int daoxu(SqStack &S1,SqStack &S2)
{
    int elem,temp;
    int i;
    temp=S1.top-S1.base;
    for(i=0;i<temp;i++)
    {
        Pop(S1,elem);
        push(S2,elem);
    }
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
int main()
{
    SqStack S1,S2;
    Init_Stack(S1);
    Init_Stack(S2);
    Inputs_SqStack(S1);
    printf_Stack(S1);
    daoxu(S1,S2);
    destory_stack(S1);
    S1=S2;
    printf_Stack(S1);
    return 0;
}
