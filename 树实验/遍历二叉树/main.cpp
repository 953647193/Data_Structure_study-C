#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
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
/*******
���������
********/
int count_depth_postorder(BiTree T)
{
    int count_dep=0;
    int lcount,rcount;
    if(T)
    {
        lcount=count_depth_postorder(T->lchild);
        rcount=count_depth_postorder(T->rchild);
        count_dep=1+(lcount>rcount?lcount:rcount);
    }
}
/**************
ǰ�����
****************/
int preorder_visit(BiTree T)
{
    if(T)
    {
        printf("%c ",T->data);
        if(preorder_visit(T->lchild))
            if(preorder_visit(T->rchild))
                return OK;
        return ERROR;
    }
    else
        return OK;
}
/************
�������
***************/
int inorder_visit(BiTree T)
{
    if(T)
    {
        if(inorder_visit(T->lchild))
        {
            printf("%c ",T->data);
            if(inorder_visit(T->rchild))
                return OK;
        }
        return ERROR;
    }
    else
        return OK;
}
/***************
�������
****************/
int postorder_visit(BiTree T)
{
    if(T)
    {
        if(postorder_visit(T->lchild))
            if(postorder_visit(T->rchild))
            {
                printf("%c ",T->data);
                return OK;
            }
        return ERROR;
    }
    else
        return OK;
}
int main()
{
    BiTree T;
    CreatBiTree(T);
    printf("ǰ�����Ϊ:\n");
    preorder_visit(T);
    printf("\n");
    printf("�������Ϊ:\n");
    inorder_visit(T);
    printf("\n");
    printf("�������Ϊ:\n");
    postorder_visit(T);
    printf("\n");
    printf("���Ϊ:%d\n",count_depth_postorder(T));
    return 0;
}
