#include<iostream>
using namespace std;
# define MAXSIZE 100
typedef struct LNode* List;         //����ܶ�ֱ����LNode��ָ��List��
                                   //ԭ��֮һ����Ϊָ�����βο����޸�ʵ��ֵ
struct LNode
{
	int Data[MAXSIZE];
	int Last;
};                                       
List MakeEmpty()                     //��ʼ���ձ�
{
	List PtrL;                       //����LNode��ָ��List
	PtrL = new LNode();              //newһ��LNode���͵ı����������ַ����PtrL
	PtrL->Last = -1;                 //�������ʼλ��Ϊ0���ʿձ��βλ��Ϊ-1
	return PtrL;                     //����ʼ����Ŀձ�ָ�뷵��
}   
void ShowList(List PtrL)             //��ʾ���Ա�
{
	for (int i = 0;i <= PtrL->Last;i++)
	{
		cout << PtrL->Data[i] << " ";
	}
	cout << "���Ա���Ϊ�� " << PtrL->Last + 1<< endl;
	return;
}
int FindList(int x, List PtrL)                     //�������Ա��е�Ԫ�� 
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != x)
		i++;
	if (i > PtrL->Last) return -1;                //���û�ҵ�������-1��
	else
		return i;                                 //�ҵ��󷵻ش洢λ��
}                                       
                                      
void Insert(int x, int i, List PtrL)    //�ڱ�ĵ�i��λ�ò���Ԫ��
{
	if (PtrL->Last == MAXSIZE - 1)      //�жϱ��Ƿ�����
	{
		cout << "����" << endl;
		return;                         //�ǵü�return�������ִ��for���
	}
	                                  
	if (i<1 || i>(PtrL->Last + 2))       //�жϲ���λ���Ƿ�Ϸ�
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return;
	}
	if  (PtrL->Last+2==i)                //���뵽���Ա��β
	{
		PtrL->Data[i-1] = x;
		PtrL->Last++;                    //��������Ա���+1
		return;
	}
for (int j = PtrL->Last;j >= i - 1;j--)   //������λ�ü����Ժ��Ԫ�ص�λ�����Ųһλ
		{
			PtrL->Data[j + 1] = PtrL->Data[j];
			PtrL->Data[i - 1] = x;
		}
		PtrL->Last++;                      
		return;
	
}
                                             //ɾ��(ɾ����ĵ�i��λ���ϵ�Ԫ��)
void Delete(int i, List PtrL)
{
	if (i<1 || i>PtrL->Last + 1)
	{
		cout << "�����ڵ�i��Ԫ��" << endl;
		return;
	}
	for (int j = i - 1;j <= PtrL->Last;j++)
	{
		PtrL->Data[j] = PtrL->Data[j + 1];
	}
	PtrL->Last--;
	return;
}
int main()
{
	    LNode *L=MakeEmpty();
	    cout << "�������Ա��в�������" << endl;
		int list_data;
		while (getchar()!='\n')           //�ڳ�ʼ�����Ա�ʱ��getchar()���̵���һ��Ԫ�أ���������ʱҪ����һ����'\n'�������ַ�
		{                                 //����ʱû�����������������������֪���Ļ���������ָ������ʤ�м���
			int list_data;
			int i=1;
			cin >> list_data;
			Insert(list_data, i, L);
			i++;
		}
		cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
		int find_data;
		cin >> find_data;
		FindList(find_data, L);
		cout << "��������Ҫ�����Ԫ�ؼ�����λ�ã�" << endl;
		int	insert_data,position;
		cin >> insert_data>>position;
		Insert(insert_data,position,L);
		cout << "��������ɾ��Ԫ�ص�λ�ã�" << endl;
		int delete_position;
		cin >> delete_position;
		Delete(delete_position, L);
	ShowList(L);
	return 0;

}