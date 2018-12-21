#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
#define List_init_size 100;
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
typedef struct
{
    elem *base;
    elem *top;
    int ListSize;
} SqStack;
/*****************
����������
*****************/
int CreatBiTree(BiTree &T)
{
    elem ch;
    scanf("%c",&ch);
    getchar();
    if(' '==ch)
        T=NULL;
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
            return OVERFLOW;
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}
/**********
����������ʼ��ջ
������SqStack
���أ�void
**********/
/**
 * ......................�ҷ�ȱ�......................
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -�d-|||||- \
 *               |   | \\\  -  /// |   |
 *               | \_|  ''\---/''  |_/ |
 *               \  .-\__  '-'  ___/-. /
 *             ___'. .'  /--.--\  `. .'___
 *          ."" '<  `.___\_<|>_/___.' >' "".
 *         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *         \  \ `_.   \_ __\ /__ _/   .-` /  /
 *     =====`-.____`.___ \_____/___.-`___.-'=====
 *                       `=---='
 *
 *..................���濪�� ,����BUG...................
 *
 */

void Init_Stack(SqStack &S)
{
    S.base=(elem *)malloc(List_init_size*sizeof(elem));    //��Ҳ��֪��Ϊʲô����
    if(!S.base)
        printf("ջ��ʼ��ʧ��\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}

/**********
������������ջ
������SqStack x
���أ�OK
**********/
int push(SqStack &S,elem x)
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
int Pop(SqStack &S,elem &x)
{
    if(S.base==S.top)
    {
        printf("ջ�Ѿ�����\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}
/********************
�ݻ�ջ
*********************/
int destory_sqstack(SqStack &S)
{
    free(S.base);
    S.top=S.base;
    S.ListSize=0;
    return OK;
}
elem get_top(SqStack &S)
{
    if(S.base==S.top)
        return ERROR;
    return *(S.top-1);
}
/*********************
�жϿ�
*********************/
int is_stack_empty(SqStack &S)
{
    if(S.base==S.top)
        return 1;
    else
        return 0;
}
/*************
·������
**************/
int find_way(BiTree T,elem p,SqStack &S)
{
    if(!T)
        return 0;
    if(find_way(T->lchild,p,S)||find_way(T->rchild,p,S))
    {
        push(S,T->data);
        return 1;
    }
    if(T->data==p)
    {
        push(S,p);
        return 1;
    }
    return 0;
}
int main()
{
    BiTree T;
    SqStack S;
    elem p;
    Init_Stack(S);
    printf("����һ������\n");
    printf("����:\n");
    scanf("%c",&p);
    find_way(T,p,S);
    while(!is_stack_empty(S))
    {
        Pop(S,p);
        printf("%c->",p);
    }
    return 0;
}
