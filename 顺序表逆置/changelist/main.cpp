#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCRMENT
#define N 60
typedef struct
{
    int *elem;
    int  length;
    int  listsize;
} SqList;
int InitList_Sq(SqList &L)
{
    //˳���
    int i;
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)
        return 0;
    for(i=0; i<N; i++)
        L.elem[i]=i;
    L.length=N;
    L.listsize=LIST_INIT_SIZE;
    return 1;
}
void ChangeList(SqList &L)
{
    int *p=&L.elem[0],temp;
    for(int i=0;i<L.length/2;i++)   //�����һ��
    {
        temp=p[i];                  //Ԫ�ؽ���
        p[i]=p[L.length-1-i];
        p[L.length-i-1]=temp;
    }
}
void pL(SqList &L)   //��ӡ��˳���
{
    for(int i=0; i<L.length; i++)
        printf("%d ",L.elem[i]);
    printf("\n");
}
int main()
{
    SqList L;
    if(InitList_Sq(L))
        pL(L);
    else
        printf("����˳���ʧ��");
    ChangeList(L);
    pL(L);
    system("pause");
    return 0;
}
