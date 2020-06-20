#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 0
#define OVERFLOW 0
#define LISTSIZE 100
#define LISTINCREMENT 100
typedef int Elemtype;
typedef int status;
typedef struct {
	Elemtype *base;
	int length;
	int listsize;
}SqList;
//����Ԫ��
status ElemInsert(SqList &List, int i, Elemtype newelem) {
	if (i<1 || i>List.length + 1) return ERROR;
	if (List.length == List.listsize) {
		Elemtype *newbase = (Elemtype *)realloc(List.base, (List.listsize + LISTINCREMENT) * sizeof(Elemtype));
		if (!newbase)exit(OVERFLOW);
		List.listsize += LISTINCREMENT;
		List.base = newbase;
	}
	Elemtype *q = &(List.base[i - 1]), *p;
	for (p = &(List.base[List.length - 1]); p >= q; --p) {
		*(p + 1) = *p; 
	}
	*q = newelem;
	++List.length;
	printf("�����ɹ�");
	return OK;
}
//ɾ��Ԫ��
status DelElem(SqList &List, int i) {
	if (i<1 || i>List.length) return ERROR;
	Elemtype *q = &(List.base[i - 1]), *p;
	for (p = &(List.base[List.length - 1]); p >= q; ++q) {
		*q = *(q + 1);
	}
	--List.length;
	printf("�����ɹ�");
	return OK;
}
//�޸�Ԫ��
status ChangeElem(SqList &List, int i, int newelem) {
	if (i<1 || i>List.length) return ERROR;
	List.base[i - 1] = newelem;
	printf("�����ɹ�");
	return OK;
}
//��ӡ����Ԫ��
void PrintList(SqList List)//��ӡ��
{
	int loop;
	printf("����Ԫ�����£�\n");
	for (loop = 0; loop < List.length; loop++) {
		printf("%d", List.base[loop]);
	}
}
//��ʼ��˳�����Ա�
status InitList(SqList &List) {
	List.base = (Elemtype *)malloc(LISTSIZE * sizeof(Elemtype));
	if (!List.base) {
		exit(OVERFLOW);
	}
	List.length = 0;
	List.listsize = LISTSIZE;
	int loop;
	printf("�������ʼ����˳���ĳ��ȣ�");
	scanf_s("%d", &List.length);
	printf("�������ĸ���Ԫ�أ��ÿո��������");
	for (loop = 0; loop < List.length; loop++) {
		scanf_s("%d", &List.base[loop]);
	}
	printf("˳������ɹ���Ԫ�ظ���Ϊ%d:", List.length);
	PrintList(List);
	return OK;
}
//������
void main() {
	SqList List;
	int command, i, elemvalue;
	InitList(List);
		printf("\n��ѡ�������1.����һ��Ԫ�� 2.ɾ��һ��Ԫ�� 3.�޸�һ��Ԫ�� 4.��ѯ������:");
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			printf("���������Ԫ�ص�ֵ��");
			scanf_s("%d", &elemvalue);
			printf("���������Ԫ�ص�λ�ã����ܴ���%d:", List.length);
			scanf_s("%d", &i);
			ElemInsert(List, i, elemvalue);
			PrintList(List);
			break;
		case 2:
			printf("������Ҫɾ���ڼ���Ԫ�أ�");
			scanf_s("%d", &i);
			DelElem(List, i);
			PrintList(List);
			break;
		case 3:
			printf("������Ҫ���ڼ���Ԫ�ش��漰�����ֵ��");
			scanf_s("%d %d", &i, &elemvalue);
			ChangeElem(List, i, elemvalue);
			PrintList(List);
			break;
		case 4:
			//�鿴����Ԫ��
			PrintList(List);
			break;

		}
		system("pause");
		return;
}
