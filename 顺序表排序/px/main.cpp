#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCRMENT
#define N 20
typedef struct
{
    int *elem;
    int  length;
    int  listsize;
} SqList;
int InitList_Sq(SqList &L)
{
    //˳���
    int i,k=1;
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)
        return 0;
    for(i=0; i<N; i++)
    {
        L.elem[i]=i*k;
        k=-k;
    }
    L.length=N;
    L.listsize=LIST_INIT_SIZE;
    return 1;
}
void px(SqList &L)
{
    int k=0,*p=&L.elem[0],temp;
    for(int i=0; i<L.length; i++)
        if(p[i]<0)   //�ж��Ƿ�С��0
        {
            temp=p[i];    //Ԫ�ؽ���
            p[i]=p[k];
            p[k]=temp;
            k++;          //����λ������
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
    px(L);
    pL(L);
    system("pause");
    return 0;
}
