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
	List P = PtrL;            //ָ�������ͷ
	int j=0;
	while (P)                 //ֻҪPָ�벻ָ��NULL��P��ָ����һ��Ԫ�أ�j����
	{
		P = P->Next;
		j++;
	}
	return j;
}
List FindKth(int k, List PtrL)              //��˳�����
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
List Find(int x, List PtrL)                 //��ֵ����
{
	List P = PtrL;
	while (P != NULL && P->Data != x)
		P = P->Next;
	return P;
}
List Insert(int x, int i, List PtrL)     //����
{
	List S = new LNode();
	if (i == 1)                          //������û�н��
	{
		S->Data = x;
		S->Next = PtrL;
		return S;                        //����ͷָ��
	}
	List P = FindKth(i-1,PtrL);
	if (P == NULL)
	{
		cout << "�������" << endl;
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
			cout << "��Ϊ�ձ�" << endl;
			return NULL;
		}
	}
	List P = FindKth(i-1,PtrL);
	if (P == NULL)
	{
		cout << "��i-1����㲻����" << endl;
		return NULL;
	}
	List S = FindKth(i, PtrL);
	if (S == NULL)
	{
		cout << "��i����㲻����" << endl;
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
