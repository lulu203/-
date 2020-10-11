#include<iostream>
using namespace std;
typedef struct  LNode* List;
struct LNode                     
{
	int Data;
	List Next;
};
int length(List PtrL)
{
	List P = PtrL;            //指向链表表头
	int j=0;
	while (P)                 //只要P指针不指向NULL，P就指向下一个元素，j计数
	{
		P = P->Next;
		j++;
	}
	return j;
}
List FindKth(int k, List PtrL)              //按顺序查找
{
	List P = PtrL;
	int i= 1;
	while (i < k && P != NULL)
	{
		P = P->Next;
		i++;
	}
	if (i == k)
	{
		cout << P->Data << endl;
		return P;
	}
	else
		return NULL;
}
List Find(int x, List PtrL)                 //按值查找
{
	List P = PtrL;
	while (P != NULL && P->Data != x)
		P = P->Next;
	return P;
}
List Insert(int x, int i, List PtrL)     //插入
{
	List S = new LNode();
	if (i == 1)                          //链表内没有结点
	{
		S->Data = x;
		S->Next = PtrL;
		return S;                        //返回头指针
	}
	List P = FindKth(i-1,PtrL);
	if (P == NULL)
	{
		cout << "插入错误" << endl;
		return NULL;
	}
	else
	{
		S->Next = P->Next;
		P->Next = S;
		return PtrL;
	}
}
List Delete(int i, List PtrL)
{
	if (i == 1)
	{
		if (PtrL != NULL)
		{
			List S = PtrL;
			PtrL = PtrL->Next;
			delete S;
			return PtrL;
		}
		else
		{
			cout << "此为空表" << endl;
			return NULL;
		}
	}
	List P = FindKth(i-1,PtrL);
	if (P == NULL)
	{
		cout << "第i-1个结点不存在" << endl;
		return NULL;
	}
	List S = FindKth(i, PtrL);
	if (S == NULL)
	{
		cout << "第i个结点不存在" << endl;
		return NULL;
	}
	P->Next = S->Next;
	delete S;
	return PtrL;
}
void Test_List(List PtrL)
{
	List P=PtrL;
	while (P != NULL)
	{
		P = P->Next;
		cout << P->Data << " ";
	}
	return;
}
int main()
{
		system("pause");
	return 0;
}
