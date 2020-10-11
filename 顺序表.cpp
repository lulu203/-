#include<iostream>
using namespace std;
# define MAXSIZE 100
typedef struct LNode* List;         //下面很多直接用LNode的指针List，
                                   //原因之一是因为指针做形参可以修改实参值
struct LNode
{
	int Data[MAXSIZE];
	int Last;
};                                       
List MakeEmpty()                     //初始化空表
{
	List PtrL;                       //声明LNode型指针List
	PtrL = new LNode();              //new一个LNode类型的变量并将其地址传给PtrL
	PtrL->Last = -1;                 //因数组初始位置为0，故空表表尾位置为-1
	return PtrL;                     //将初始化后的空表指针返回
}   
void ShowList(List PtrL)             //显示线性表
{
	for (int i = 0;i <= PtrL->Last;i++)
	{
		cout << PtrL->Data[i] << " ";
	}
	cout << "线性表长度为： " << PtrL->Last + 1<< endl;
	return;
}
int FindList(int x, List PtrL)                     //查找线性表中的元素 
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != x)
		i++;
	if (i > PtrL->Last) return -1;                //如果没找到，返回-1；
	else
		return i;                                 //找到后返回存储位置
}                                       
                                      
void Insert(int x, int i, List PtrL)    //在表的第i个位置插入元素
{
	if (PtrL->Last == MAXSIZE - 1)      //判断表是否已满
	{
		cout << "表满" << endl;
		return;                         //记得加return否则程序将执行for语句
	}
	                                  
	if (i<1 || i>(PtrL->Last + 2))       //判断插入位置是否合法
	{
		cout << "插入位置不合法" << endl;
		return;
	}
	if  (PtrL->Last+2==i)                //插入到线性表表尾
	{
		PtrL->Data[i-1] = x;
		PtrL->Last++;                    //插入后线性表长度+1
		return;
	}
for (int j = PtrL->Last;j >= i - 1;j--)   //将插入位置及其以后的元素的位置向后挪一位
		{
			PtrL->Data[j + 1] = PtrL->Data[j];
			PtrL->Data[i - 1] = x;
		}
		PtrL->Last++;                      
		return;
	
}
                                             //删除(删除表的第i个位置上的元素)
void Delete(int i, List PtrL)
{
	if (i<1 || i>PtrL->Last + 1)
	{
		cout << "不存在第i个元素" << endl;
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
	    cout << "请在线性表中插入数据" << endl;
		int list_data;
		while (getchar()!='\n')           //在初始化线性表时，getchar()会吞掉第一个元素，所以运行时要输入一个非'\n'的无用字符
		{                                 //我暂时没有想出来解决方法，如果有人知道的话请在评论指出，不胜感激；
			int list_data;
			int i=1;
			cin >> list_data;
			Insert(list_data, i, L);
			i++;
		}
		cout << "请输入您要查找的元素：" << endl;
		int find_data;
		cin >> find_data;
		FindList(find_data, L);
		cout << "请输入您要插入的元素及插入位置：" << endl;
		int	insert_data,position;
		cin >> insert_data>>position;
		Insert(insert_data,position,L);
		cout << "请输入你删除元素的位置：" << endl;
		int delete_position;
		cin >> delete_position;
		Delete(delete_position, L);
	ShowList(L);
	return 0;

}