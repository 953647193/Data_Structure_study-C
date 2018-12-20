#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1
#define elem int
#define queue_init_size 100
typedef struct queue
{
    elem *base;
    int front;
    int rear;
    int len;
} queue;
/*********
��ʼ������
***********/
int queue_init(queue *Q,int n)
{
    Q->base=(elem *)malloc((n+1)*sizeof(elem));
    if(!Q)
        return ERROR;
    Q->len=n+1;
    Q->front=Q->rear=0;
    return OK;
}
/************
��ն���
*************/
int clear_queue(queue *Q)
{
    Q->rear=Q->front;
    return OK;
}
/************
����Ԫ��
**************/
int Enqueue(queue *Q,elem data)
{
    if((Q->rear+1)%Q->len==Q->front)
    {
        printf("��������\n");
        return OVERFLOW;
    }
    Q->base[Q->rear]=data;
    Q->rear=(Q->rear+1)%Q->len;
    return OK;
}
/*****************
�õ���ͷ
********************/
int get_head(queue *Q,elem * data)
{
    if(Q->front==Q->rear)
    {
        printf("����Ϊ��\n");
        return ERROR;
    }
    *data=Q->base[Q->front];
    return OK;
}
/*******************
������
***********************/
int Dequeue(queue *Q,elem *data)
{
    if(Q->front==Q->rear)
    {
        printf("����Ϊ��\n");
        return ERROR;
    }
    *data=Q->base[Q->front];
    Q->front=(Q->front+1)%Q->len;
    return OK;
}
/********************
�������
**********************/
int printf_queue(queue *Q)
{
    int i;
    if(Q->front==Q->rear)
        printf("��\n");
    else if(Q->front<Q->rear)
    {
        for(i=Q->front; i<Q->rear; i++)
            printf("%d ",Q->base[i]);
    }
    else if(Q->front>Q->rear)
    {
        for(i=Q->front; i<Q->len; i++)
            printf("%d ",Q->base[i]);
        for(i=0; i<Q->rear; i++)
            printf("%d ",Q->base[i]);
    }
    printf("\b\n");
    return OK;
}
void print_mune()
{
    printf("��������Ҫ�Ĺ���\n");
    printf("1����ʼ������\n");
    printf("2����ն���\n");
    printf("3��������Ԫ��\n");
    printf("4����ö�ͷԪ��\n");
    printf("5��ɾ����ͷ\n");
    printf("6���������\n");
    printf("7���˳�\n");
}
int main()
{
    queue Q;
    int n=queue_init_size;
    int i;
    int flag=1;
    elem data;
    while(flag)
    {
        print_mune();
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            printf("��������г�\n");
            scanf("%d",&n);
            queue_init(&Q,n);
            break;
        case 2:
            clear_queue(&Q);
            break;
        case 3:
            printf("������Ҫ�����Ԫ��\n");
            scanf("%d",&data);
            Enqueue(&Q,data);
            break;
        case 4:
            get_head(&Q,&data);
            printf("��ͷ��%d\n",data);
            break;
        case 5:
            Dequeue(&Q,&data);
            printf("��ɾ������%d\n",data);
            break;
        case 6:
            printf_queue(&Q);
            break;
        case 7:
            flag=0;
            break;
        }
    }
    return 0;
}
