#include"stdio.h"
#include"stdlib.h"
#define ERROR 0
#define OK 1
typedef int Elemtype;
typedef int status;
typedef struct LNode {
	Elemtype data;
	struct LNode *next;
}LNode, *LinkList;
status InitList() {
	LNode *L;
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		printf("空间申请失败\n");
	L->next = NULL;
	return 0;
}
void CreateList(LinkList &L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		printf("分配内存失败！\n");

	}
	L->next = NULL;
	printf("请输入%d个元素：", n);
	for (int i = n; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));

		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

status InsertList(LinkList &L, int i, Elemtype e) {
	LNode *p = L, *s;
	int j = 0;
	while (p&&j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
		printf("Insert ERROR!");
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("Insert OK");
	return OK;
}
status DeleteList(LinkList &L, int i, Elemtype &e) {
	LNode *p = L, *q;
	int j = 0;
	printf("输入元素删除位置:");
	scanf_s("%d", &i);
	while (p->next && j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	printf("Delete OK");
	return OK;
}
status ChangeList(LinkList &L, int i, Elemtype &e) {
	LinkList p;
	Elemtype m;
	int j;
	p = L->next;
	j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
	{
		printf("修改位置ERROR\n");
		return ERROR;
	}
	m = p->data;
	p->data = e;
	return OK;
}
status GetElem(LinkList L, int i, Elemtype &e) {
	int j = 0;
	LinkList p = L->next;
	while (p && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i - 1)
	{
		printf("该元素不存在！\n");
		return ERROR;
	}
	e = p->data;
	printf("第 %d 个元素为 %d\n", i, e);
	return OK;
}
void PrintList(LinkList List)
{
	LinkList p;
	printf("链表：\n");
	p = List->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{

	LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	printf("操作成功\n");
	PrintList(Lc);
}
int main()
{
	LinkList La, Lb, Lc;
	LinkList List;
	int a, b, c, n;
	printf("链表长度：");
	scanf_s("%d", &n);
	CreateList(List, n);
	PrintList(List);
	int i = 1;
	while (i)
	{
		printf("输入想要进行的操作 1.增加一个元素 2.删除一个元素 3.修改一个元素 4.查找一个元素 5.两个链表归并：");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			printf("输入元素插入位置:");
			scanf_s("%d", &b);
			printf("输入元素:");
			scanf_s("%d", &c);
			InsertList(List, b, c);
			PrintList(List);
			break;
		case 2:
			DeleteList(List, b, c);
			PrintList(List);
			break;
		case 3:
			printf("输入修改位置：");
			scanf_s("%d", &b);
			printf("输入替换的元素：");
			scanf_s("%d", &c);
			ChangeList(List, b, c);
			PrintList(List);
			break;
		case 4:
			printf("请输入要查找的元素位置i：");
			scanf_s("%d", &b);
			GetElem(List, b, c);
			printf("\n");
			break;
		case 5:
			printf("创建La：\n");
			printf("La长度为？");
			scanf_s("%d", &b);
			CreateList(La, b);
			printf("创建Lb：\n");
			printf("Lb长度为？");
			scanf_s("%d", &c);
			CreateList(Lb, c);
			MergeList(La, Lb, Lc);
			PrintList(Lc);
			break;
		}
	}
	return 0;
}
