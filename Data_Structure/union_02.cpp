#include <stdio.h>
#include "Sequence_List.cpp"

int equal(LElemType_Sq e1, LElemType_Sq e2)
{
   return e1==e2 ? TRUE : FALSE;
}

/*将所有线性表Lb中但不在La中的数据元素插入到La中，return La=La+Lb*/
void Union(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	int i;
	LElemType_Sq e;

	La_len = ListLength_Sq(*La);			//求顺序表长度
	Lb_len = ListLength_Sq(Lb);

	for(i=1; i<=Lb_len; i++)
	{
		GetElem_Sq(Lb, i, &e);				//取Lb中第i个元素赋给e
		if(!LocateElem_Sq(*La, e, equal)) 	//若e不在La中则插入
			ListInsert_Sq(La, ++La_len, e);
	}
}

int main(){
    //测试
    SqList La, Lb;
	LElemType_Sq a[5] = {5, 2, 1, 3, 9};
	LElemType_Sq b[7] = {7, 2, 6, 9, 11, 3, 10};
	int i;

	InitList_Sq(&La);					//初始化La
	for(i=1; i<=5; i++)
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

	printf("La = La∪Lb = ");			//输出新表La的内容
	Union(&La, Lb);
	ListTraverse_Sq(La, PrintElem);
	printf("\n\n");

	return 0;
}
