#include <stdio.h>
#include "Sequence_List.cpp"

void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)	//����˳��������кϲ�
{
	int La_len, Lb_len;
	int i, j, k;
	LElemType_Sq ai, bj;

	i = j = 1;
	k = 0;

	InitList_Sq(Lc);					//��ʼ��Lc
	La_len = ListLength_Sq(La);			//��ȡLa��Lb����
	Lb_len = ListLength_Sq(Lb);

	while(i<=La_len && j<=Lb_len)		//La��Lb��δɨ����
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

	while(i<=La_len)					//��La��δɨ����
	{
		GetElem_Sq(La, i++, &ai);
		ListInsert_Sq(Lc, ++k, ai);
	}

	while(j<=Lb_len)					//��Lb��δɨ����
	{
		GetElem_Sq(Lb, j++, &bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}

int main(){
    //����
    SqList La, Lb, Lc1;
	LElemType_Sq a[4] = {3, 5, 8, 11};
	LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;

	InitList_Sq(&La);					//��ʼ��La
	for(i=1; i<=4; i++)
		ListInsert_Sq(&La, i, a[i-1]);
	InitList_Sq(&Lb);					//��ʼ��Lb
	for(i=1; i<=7; i++)
		ListInsert_Sq(&Lb, i, b[i-1]);

	printf("La = ");					//���La
	ListTraverse_Sq(La, PrintElem);
	printf("\n");
	printf("Lb = ");					//���Lb
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");

	MergeSqList_1(La, Lb, &Lc1);		//�ϲ�A��B,�㷨2.6
	printf("�ϲ�La��LbΪLc1 = "); 		//���Lc1
	ListTraverse_Sq(Lc1, PrintElem);
	printf("\n\n");

	return 0;
}
