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
//插入元素
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
	printf("操作成功");
	return OK;
}
//删除元素
status DelElem(SqList &List, int i) {
	if (i<1 || i>List.length) return ERROR;
	Elemtype *q = &(List.base[i - 1]), *p;
	for (p = &(List.base[List.length - 1]); p >= q; ++q) {
		*q = *(q + 1);
	}
	--List.length;
	printf("操作成功");
	return OK;
}
//修改元素
status ChangeElem(SqList &List, int i, int newelem) {
	if (i<1 || i>List.length) return ERROR;
	List.base[i - 1] = newelem;
	printf("操作成功");
	return OK;
}
//打印所有元素
void PrintList(SqList List)//打印表
{
	int loop;
	printf("表中元素如下：\n");
	for (loop = 0; loop < List.length; loop++) {
		printf("%d", List.base[loop]);
	}
}
//初始化顺序线性表
status InitList(SqList &List) {
	List.base = (Elemtype *)malloc(LISTSIZE * sizeof(Elemtype));
	if (!List.base) {
		exit(OVERFLOW);
	}
	List.length = 0;
	List.listsize = LISTSIZE;
	int loop;
	printf("请输入初始化的顺序表的长度：");
	scanf_s("%d", &List.length);
	printf("请输入表的各个元素，用空格键隔开：");
	for (loop = 0; loop < List.length; loop++) {
		scanf_s("%d", &List.base[loop]);
	}
	printf("顺序表创建成功，元素个数为%d:", List.length);
	PrintList(List);
	return OK;
}
//主程序
void main() {
	SqList List;
	int command, i, elemvalue;
	InitList(List);
		printf("\n请选择操作：1.插入一个元素 2.删除一个元素 3.修改一个元素 4.查询整个表:");
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			printf("请输入插入元素的值：");
			scanf_s("%d", &elemvalue);
			printf("请输入插入元素的位置，不能大于%d:", List.length);
			scanf_s("%d", &i);
			ElemInsert(List, i, elemvalue);
			PrintList(List);
			break;
		case 2:
			printf("请输入要删除第几个元素：");
			scanf_s("%d", &i);
			DelElem(List, i);
			PrintList(List);
			break;
		case 3:
			printf("请输入要将第几个元素代替及代替的值：");
			scanf_s("%d %d", &i, &elemvalue);
			ChangeElem(List, i, elemvalue);
			PrintList(List);
			break;
		case 4:
			//查看所有元素
			PrintList(List);
			break;

		}
		system("pause");
		return;
}
