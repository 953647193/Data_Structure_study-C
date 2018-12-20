#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next=NULL;
} LNode, *LinkList;
void CreateList_L(LinkList &L,int n)
{
    LinkList p=NULL;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=0; i<n; i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
    }
}
void DelMaxL(LinkList &L)
{
    LinkList p=NULL,q=NULL;
    int max_data;
    p=L->next;    //����֤�ڵ�
    max_data=p->data;
    q=L;       //����֤�ڵ��ǰһ���ڵ�
    while(p)   //�ж��Ƿ�����ĩβ
    {
        if(p->next&&(p->next)->data>max_data)  //�ж��Ƿ�ΪΪ���
        {
            q=p;  //�������ֵ�ڵ����һ���ڵ�
            max_data=(p->next)->data;//�������ֵ
        }
        p=p->next;
    }
    p=q->next;//ɾ���ڵ�
    q->next=p->next;
    free(p);//�ͷſռ�
}
void prL(LinkList &L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    LinkList L=NULL;
    int n;
    printf("��������Ҫ��Ԫ��������");
    scanf("%d",&n);
    CreateList_L(L,n);
    prL(L);
    DelMaxL(L);
    prL(L);
    system("pause");
    return 0;
}
