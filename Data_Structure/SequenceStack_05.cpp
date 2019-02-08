#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "Scanf.c"
/*栈基本算法实现*/
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

#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量

typedef int Status;
typedef int SElemType_Sq;

typedef struct
{
	SElemType_Sq *base;				//在栈构造之前和销毁之后，base的值为NULL
	SElemType_Sq *top;				//栈顶指针
	int stacksize;					//当前已分配的存储空间，以元素为单位
}SqStack;

//构造一个空栈S
Status InitStack_Sq(SqStack *S)
{
 	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);

	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;

	return OK;
}

//销毁栈S
Status DestroyStack_Sq(SqStack *S)
{
	free((*S).base);

	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;

	return OK;
}

//将S清为空栈
Status ClearStack_Sq(SqStack *S)
{
	(*S).top = (*S).base;

	return OK;
}

//若栈S为空栈，则返回TRUE,否则返回FALSE
Status StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

//返回S的元素个数，即栈的长度
int StackLength_Sq(SqStack S)
{
	return S.top - S.base;
}

//用e返回S的栈顶元素
Status GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.top==S.base)
		return ERROR;

	*e = *(S.top - 1);							//并不破坏栈

	return OK;

}

//插入元素e为新的栈顶元素
Status Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//栈满，追加存储空间
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}

	*(S->top) = e;								//进栈先赋值，栈顶指针再自增
	(S->top)++;

	return OK;
}

//删除S的栈顶元素
Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//出栈栈顶指针先递减，再赋值
	*e = *((*S).top);

	return OK;
}

//遍历
Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{												//遍历不应该破坏栈
	SElemType_Sq *p = S.base;

	while(p<S.top)
		Visit(*p++);

	return OK;
}

void PrintElem(SElemType_Sq e)
{
	printf("%d ", e);
}

int main(){
    //测试
	SqStack S;
	int i;
	SElemType_Sq e;

	printf("▼1\n▲函数 InitStack 测试...\n");			//1.函数InitStack测试
	{
		printf("初始化顺序栈 S ...\n");
		InitStack_Sq(&S);
		printf("\n");
	}


	printf("▼4\n▲函数 StackEmpty 测试...\n");			//4.函数StackEmpty测试
	{
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}


	printf("▼7\n▲函数 Push 测试...\n");					//7.函数Push测试
	{
		for(i=1; i<=6; i++)
		{
			printf("将 \"%2d\" 压入栈 S ", 2*i);
			Push_Sq(&S, 2*i);
			printf("（累计第 %d 个元素）...\n", S.top-S.base);
		}
		printf("\n");
	}


	printf("▼9\n▲函数 StackTraverse 测试...\n");		//9.函数StackTraverse测试
	{
		printf(" S 中的元素为：S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}


	printf("▼8\n▲函数 Pop 测试...\n");					//8.函数Pop测试
	{
		Pop_Sq(&S, &e);
		printf("栈顶元素 \"%d\" 出栈...\n", e);
		printf(" S 中的元素为：S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}


	printf("▼5\n▲函数 StackLength 测试...\n");			//5.函数StackLength测试
	{
		i = StackLength_Sq(S);
		printf(" S 的长度为 %d \n", i);
		printf("\n");
	}


	printf("▼6\n▲函数 GetTop 测试...\n");				//6.函数GetTop测试
	{
		GetTop_Sq(S, &e);
		printf("栈顶元素的值为 \"%d\" \n", e);
		printf("\n");
	}


	printf("▼3\n▲函数 ClearStack 测试...\n");			//3.函数ClearStack测试
	{
		printf("清空 S 前：");
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		ClearStack_Sq(&S);
		printf("清空 S 后：");
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}


	printf("▼2\n▲函数 DestroyStack 测试...\n");			//2.函数DestroyStack测试
	{
		printf("销毁 S 前：");
		S.base!=NULL && S.top!=NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
		DestroyStack_Sq(&S);
		printf("销毁 S 后：");
		S.base!=NULL && S.top!=NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
		printf("\n");
	}

	return 0;

}
