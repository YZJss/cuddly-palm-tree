#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "Scanf.c"
/*线性链表基本算法实现*/
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

typedef int LElemType_L;

/* 单链表结构体 */
typedef struct LNode
{
	LElemType_L data;
	struct LNode* next;
}LNode;

typedef LNode* LinkList;		//指向单链表结点的指针

//构造一个空的线性链表L
int InitList_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;

	return OK;
}

//将线性链表L重置为空表，并释放原链表的节点空间
int ClearList_L(LinkList L)			//保留头结点
{
	LinkList pre, p;

	if(!L)
		return ERROR;

	pre = L->next;

	while(pre)
	{
		p = pre->next;
		free(pre);
		pre = p;
	}

	L->next = NULL;

	return OK;
}

//销毁线性链表L
void DestroyList_L(LinkList *L)			//销毁所有结点
{
	LinkList p = *L;

	while(p)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
}

//若线性链表L为空表，则返回TURE,否则返回FALSE
int ListEmpty_L(LinkList L)
{
	if(L!=NULL && L->next==NULL)		//链表存在且只有头结点
		return TRUE;
	else
		return FALSE;
}

//返回线性链表L中元素个数
int ListLength_L(LinkList L)
{
	LinkList p;
	int i;

	if(L)
	{
		i = 0;
		p = L->next;
		while(p)
		{
			i++;
			p = p->next;
		}
	}

	return i;
}

/*════╗
║ 算法2.8║
╚════*/
//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
int GetElem_L(LinkList L, int i, LElemType_L *e)
{
	int j;
	LinkList p = L->next;

	j = 1;
	p = L->next;

	while(p && j<i)						//p不为空且还未到达i处
	{
		j++;
		p = p->next;
	}

	if(!p || j>i)						//第i个元素不存在
		return ERROR;

	*e = p->data;

	return OK;
}

//
int LocateElem_L(LinkList L, LElemType_L e, int(Compare)(LElemType_L, LElemType_L))
{
	int i;
	LinkList p;

	i = -1;								//L不存在时返回-1

	if(L)
	{
		i = 0;
		p = L->next;

		while(p)
		{
			i++;

			if(!Compare(e, p->data))
			{
				p = p->next;
				if(p==NULL)		//失配时已经是最后一个结点
					i++;
			}
			else
				break;
		}
	}

	return i;
}



/*════╗
║ 算法2.9║
╚════*/
//在带头节点的单链线性表L中第i个位置之前插入元素e
int ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p, s;
	int j;

	p = L;
	j = 0;

	while(p && j<i-1)					//寻找第i-1个结点
	{
		p = p->next;
		++j;
	}

	if(!p || j>i-1)
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

/*═════╗
║ 算法2.10 ║
╚═════*/
//在带头节点的单链线性表L中，删除第i个位置，并由e返回其值
int ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList pre, p;
	int j;

	pre = L;
	j = 1;

	while(pre->next && j<i)			//寻找第i个结点，并令pre指向其前驱
	{
		pre = pre->next;
		++j;
	}

	if(!pre->next || j>i)			//删除位置不合理
		return ERROR;

	p = pre->next;
	pre->next = p->next;
	*e = p->data;
	free(p);

	return OK;
}

//遍历
int ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
	LinkList p;

	if(!L)
		return ERROR;
	else
		p = L->next;

	while(p)
	{
		Visit(p->data);
		p = p->next;
	}

	return OK;
}

//用pre_e接收cur_e的前驱
int PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p, suc;

	if(L)
	{
		p = L->next;

		if(p->data!=cur_e)				//第一个结点无前驱
		{
			while(p->next)				//若p结点有后继
			{
				suc = p->next;			//suc指向p的后继
				if(suc->data==cur_e)
				{
					*pre_e = p->data;
					return OK;
				}
				p = suc;
			}
		}
	}

	return ERROR;
}

//用next_e接收cur_e的后继
int NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p, suc;

	if(L)
	{
		p = L->next;

		while(p && p->next)
		{
			suc = p->next;

			if(suc && p->data==cur_e)
			{
				*next_e = suc->data;
				return OK;
			}

			if(suc)
				p = suc;
			else
				break;
		}
	}

	return ERROR;
}

/*用visit函数访问顺序表L*/
//printf遍历

void PrintElem(int e)
{
	printf("%d ", e);
}

int CmpGreater(LElemType_L e, LElemType_L data)
{
	return data>e ? TRUE : FALSE;
}

int main(){
    //测试
	LinkList L;
	int i;
	LElemType_L e;

	printf("▼1\n▲函数 InitList_L 测试...\n");			//1.函数InitList_L测试
	{
		printf("初始化单链表 L ...\n");
		InitList_L(&L);
		printf("\n");
	}


	printf("▼4\n▲函数 ListEmpty_L 测试...\n");		//4.函数ListEmpty_L测试
	{
		ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	}


	printf("▼10\n▲函数 ListInsert_L 测试...\n");		//10.函数ListInsert_L测试
	{
		for(i=1; i<=6; i++)
		{
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert_L(L, i, 2*i);
		}
		printf("\n");
	}


	printf("▼12\n▲函数 ListTraverse_L 测试...\n");	//12.函数ListTraverse_L测试
	{
		printf(" L 中的元素为：L = ");
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	}


	printf("▼5\n▲函数 ListLength_L 测试...\n");		//5.函数ListLength_L测试
	{
		printf(" L 的长度为 %d \n", ListLength_L(L));
		printf("\n");
	}


	printf("▼11\n▲函数 ListDelete_L 测试...\n");		//11.函数ListDelete_L测试
	{
		ListDelete_L(L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为：L = ");
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	}


	printf("▼6\n▲函数 GetElem_L 测试...\n");			//6.函数GetElem_L测试
	{
		GetElem_L(L, 4, &e);
		printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
		printf("\n");
	}


	printf("▼7\n▲函数 LocateElem_L 测试...\n");		//7.函数LocateElem_L测试
	{
		i = LocateElem_L(L, 13, CmpGreater);
		printf(" L 中第一个元素值大于 \"7\" 的元素的位置为 %d \n", i);
		printf("\n");
	}


	printf("▼8\n▲函数 PriorElem_L 测试...\n");		//8.函数PriorElem_L测试
	{
		PriorElem_L(L, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
		printf("\n");
	}


	printf("▼9\n▲函数 NextElem_L 测试...\n");			//9.函数NextElem_L测试
	{
		NextElem_L(L, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
		printf("\n");
	}


	printf("▼2\n▲函数 ClearList_L 测试...\n");		//2.函数ClearList_L测试
	{
		printf("清空 L 前：");
		ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		ClearList_L(L);
		printf("清空 L 后：");
		ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	}


	printf("▼3\n▲函数 DestroyList_L 测试...\n");		//3.函数DestroyList_L测试
	{
		printf("销毁 L 前：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		DestroyList_L(&L);
		printf("销毁 L 后：");
		L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		printf("\n");
	}

}
