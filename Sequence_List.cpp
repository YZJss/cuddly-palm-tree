#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*线性表基本算法实现*/
/* 状态码 */
#define	TRUE		1			//真
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功
#define UNSUCCESS	0			//失败
#define	INFEASIBLE	-1			//不可行

#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢

#define LIST_INIT_SIZE 100				//顺序表存储空间的初始分配量
#define LISTINCREMENT  10				//顺序表存储空间的分配增量
//typedef int Status;
typedef int LElemType_Sq;

typedef struct
{
	LElemType_Sq *elem;					//存储空间基址（指向第一个结点的指针）
	int length;							//当前顺序表长度
	int listsize;						//当前分配的存储容量
}SqList;								//顺序表0号单元正常使用


/*构造一个空的线性表L*/
int InitList_Sq(SqList *L)
{
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW); 				//分配内存失败

	(*L).length = 0;					//初始化顺序表长度为0
	(*L).listsize = LIST_INIT_SIZE;		//顺序表初始内存分配量

	return OK;							//初始化成功
}

/*将L重置为空表*/
void ClearList_Sq(SqList *L)
{
	(*L).length = 0;
}


/*销毁线性表L*/
void DestroyList_Sq(SqList *L)
{
	free((*L).elem);

	(*L).elem = NULL;					//释放内存后置空指针
	(*L).length = 0;
	(*L).listsize = 0;
}

/*若L为空表，则返回TRUE,反之FALSE*/
int ListEmpty_Sq(SqList L)
{
	return 	L.length==0 ? TRUE : FALSE;
}

/*返回L中数据元素个数*/
int ListLength_Sq(SqList L)
{
	return L.length;
}


/*用e返回L中第i个数据元素的值*/
int GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	if(i<1 || i>L.length)
		return ERROR;					//i值不合法
	else
		*e = L.elem[i-1];

	return OK;
}


/*返回顺序表L中首个与e满足Compare关系的元素位序*/
//Compare函数

int compare(int e1, int e2)
{
	return e1>e2 ? TRUE : FALSE;
}

int LocateElem_Sq(SqList L, LElemType_Sq e, int(Compare)(LElemType_Sq, LElemType_Sq))
{
	int i = 1;							//i的初值为第一个元素的位序

	while(i<=L.length && !Compare(e, L.elem[i-1]))
		++i;

	if(i<=L.length)
		return i;
	else
		return 0;
}

/*用pre_e接收cur_e的前驱*/
int PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	int i = 1;

	if(L.elem[0]!=cur_e)				//第一个结点无前驱
	{
		while(i<L.length && L.elem[i]!=cur_e)
			++i;

		if(i<L.length)
		{
			*pre_e = L.elem[i-1];
			return OK;
		}
	}

	return ERROR;
}

/*用next_e接收cur_e的后继*/
int NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	int i = 0;

	while(i<L.length && L.elem[i]!=cur_e)
		++i;

	if(i<L.length-1)					//最后一个结点无后继
	{
		*next_e = L.elem[i+1];
		return OK;
	}

	return ERROR;
}


/*在L中第i个位置之前插入新元素e，L的长度加1*/
int ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	LElemType_Sq *newbase;
	LElemType_Sq *p, *q;

	if(i<1 || i>(*L).length+1)
		return ERROR;					//i值不合法

	if((*L).length >= (*L).listsize)	//若存储空间已满，需开辟新空间
	{
		newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}

	q = &(*L).elem[i-1];				//q为插入位置

	for(p=&(*L).elem[(*L).length-1]; p>=q; --p)
		*(p+1) = *p;					//插入位置及之后的元素右移

	*q = e;								//插入e
	(*L).length++;						//表长增1

	return OK;
}


/*删除L的第i个数据元素，并用e返回其值，L的长度减1*/
int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	LElemType_Sq *p, *q;

	if(i<1 || i>(*L).length)
		return ERROR;					//i值不合法

	p = &(*L).elem[i-1];				//p为被删除元素的位置
	*e = *p;
	q = (*L).elem+(*L).length-1; 		//表尾元素位置

	for(++p; p<=q; ++p)
		*(p-1) = *p;					//被删元素之后的元素左移

	(*L).length--;						//表长减1

	return OK;
}

/*用visit函数访问顺序表L*/
//printf遍历

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}

int ListTraverse_Sq(SqList L, void(PrintElem)(LElemType_Sq))
{
	int i;

	for(i=0; i<L.length; i++)
		PrintElem(L.elem[i]);

	return OK;
}

int main(){
    //测试
    int i,e;
    SqList L;
    InitList_Sq(&L);
    for(i=1; i<=6; i++)
		{
			printf("作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, 2*i);
			ListInsert_Sq(&L, i, 2*i);  //插入元素
		}
		printf("\n");
    ListTraverse_Sq(L, PrintElem);      //遍历

    ListDelete_Sq(&L, 5, &e);           //删除
    printf("\n删除 L 中第 5 个元素 \"%d\" ...\n", e);
    printf(" L 中的元素为：L = ");
    ListTraverse_Sq(L, PrintElem);
    printf("\n");

    GetElem_Sq(L, 4, &e);               //查找
    printf("\n L 中第 4 个位置的元素为 \"%d\" \n", e);
    printf("\n");

}
