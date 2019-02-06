#include <stdio.h>
#include "Sequence_List.cpp"

//已知线性表La和Lb中的数据元素按值非递减排列
//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)	//调用顺序表函数进行合并
{
	int La_len, Lb_len;
	int i, j, k;
	LElemType_Sq ai, bj;

	i = j = 1;
	k = 0;

	InitList_Sq(Lc);					//初始化Lc
	La_len = ListLength_Sq(La);			//获取La、Lb长度
	Lb_len = ListLength_Sq(Lb);

	while(i<=La_len && j<=Lb_len)		//La及Lb均未扫描完
	{
		GetElem_Sq(La, i, &ai);
     	GetElem_Sq(Lb, j, &bj);

     	if(ai<=bj)
     	{
     		ListInsert_Sq(Lc, ++k, ai);
     		i++;
     	}
     	else
     	{
			ListInsert_Sq(Lc, ++k, bj);
			j++;
		}
	}

	while(i<=La_len)					//表La还未扫描完
	{
		GetElem_Sq(La, i++, &ai);
		ListInsert_Sq(Lc, ++k, ai);
	}

	while(j<=Lb_len)					//表Lb还未扫描完
	{
		GetElem_Sq(Lb, j++, &bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}

int main(){
    //测试
    SqList La, Lb, Lc1;
	LElemType_Sq a[4] = {3, 5, 8, 11};
	LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;

	InitList_Sq(&La);					//初始化La
	for(i=1; i<=4; i++)
		ListInsert_Sq(&La, i, a[i-1]);
	InitList_Sq(&Lb);					//初始化Lb
	for(i=1; i<=7; i++)
		ListInsert_Sq(&Lb, i, b[i-1]);

	printf("La = ");					//输出La
	ListTraverse_Sq(La, PrintElem);
	printf("\n");
	printf("Lb = ");					//输出Lb
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");

	MergeSqList_1(La, Lb, &Lc1);		//合并A与B,算法2.6
	printf("合并La和Lb为Lc1 = "); 		//输出Lc1
	ListTraverse_Sq(Lc1, PrintElem);
	printf("\n\n");

	return 0;
}
