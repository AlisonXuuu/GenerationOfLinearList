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
		printf("�ռ�����ʧ��\n");
	L->next = NULL;
	return 0;
}
void CreateList(LinkList &L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		printf("�����ڴ�ʧ�ܣ�\n");

	}
	L->next = NULL;
	printf("������%d��Ԫ�أ�", n);
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
	printf("����Ԫ��ɾ��λ��:");
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
		printf("�޸�λ��ERROR\n");
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
		printf("��Ԫ�ز����ڣ�\n");
		return ERROR;
	}
	e = p->data;
	printf("�� %d ��Ԫ��Ϊ %d\n", i, e);
	return OK;
}
void PrintList(LinkList List)
{
	LinkList p;
	printf("����\n");
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
	printf("�����ɹ�\n");
	PrintList(Lc);
}
int main()
{
	LinkList La, Lb, Lc;
	LinkList List;
	int a, b, c, n;
	printf("�����ȣ�");
	scanf_s("%d", &n);
	CreateList(List, n);
	PrintList(List);
	int i = 1;
	while (i)
	{
		printf("������Ҫ���еĲ��� 1.����һ��Ԫ�� 2.ɾ��һ��Ԫ�� 3.�޸�һ��Ԫ�� 4.����һ��Ԫ�� 5.��������鲢��");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			printf("����Ԫ�ز���λ��:");
			scanf_s("%d", &b);
			printf("����Ԫ��:");
			scanf_s("%d", &c);
			InsertList(List, b, c);
			PrintList(List);
			break;
		case 2:
			DeleteList(List, b, c);
			PrintList(List);
			break;
		case 3:
			printf("�����޸�λ�ã�");
			scanf_s("%d", &b);
			printf("�����滻��Ԫ�أ�");
			scanf_s("%d", &c);
			ChangeList(List, b, c);
			PrintList(List);
			break;
		case 4:
			printf("������Ҫ���ҵ�Ԫ��λ��i��");
			scanf_s("%d", &b);
			GetElem(List, b, c);
			printf("\n");
			break;
		case 5:
			printf("����La��\n");
			printf("La����Ϊ��");
			scanf_s("%d", &b);
			CreateList(La, b);
			printf("����Lb��\n");
			printf("Lb����Ϊ��");
			scanf_s("%d", &c);
			CreateList(Lb, c);
			MergeList(La, Lb, Lc);
			PrintList(Lc);
			break;
		}
	}
	return 0;
}
